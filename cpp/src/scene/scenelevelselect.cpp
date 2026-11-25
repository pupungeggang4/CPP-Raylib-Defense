#include "scene.hpp"

#include "asset.hpp"
#include "ui.hpp"

#include "util.hpp"
#include "render.hpp"

#include "game.hpp"

SceneLevelSelect::SceneLevelSelect() {
    
}

void SceneLevelSelect::ready(Game& game) {
    page = 0;
    selectedLevel = -1;
}

void SceneLevelSelect::update(Game& game) {
}

void SceneLevelSelect::render(Game& game) {
    Render::drawText("Select Level", UI::UILevelSelect["text_title"]);
    Render::drawTexture(Asset::texture["button_back"], UI::UILevelSelect["button_back"]);

    for (int i = 0; i < 15; i++) {
        int col = i % 5;
        int row = (i - col) / 5;
        std::array<float, 6> rect = {
            UI::UILevelSelect["button_level"][0] + UI::UILevelSelect["button_level"][2] * col,
            UI::UILevelSelect["button_level"][1] + UI::UILevelSelect["button_level"][3] * row,
            UI::UILevelSelect["button_level"][4], UI::UILevelSelect["button_level"][5]
        };
        if (i != selectedLevel) {
            Render::drawRect(rect, YELLOW);
        } else {
            Render::drawRect(rect, GREEN);
        }
        std::array<float, 6> pos = {rect[0] + UI::UILevelSelect["text_level"][0], rect[1] + UI::UILevelSelect["text_level"][1]};
        Render::drawText(TextFormat("%d-%d", page + 1, i + 1), pos);
    }

    Render::drawRect(UI::UILevelSelect["button_prev"], YELLOW);
    Render::drawText("Prev", UI::UILevelSelect["text_prev"]);
    Render::drawRect(UI::UILevelSelect["button_next"], YELLOW);
    Render::drawText("Next", UI::UILevelSelect["text_next"]);
    Render::drawRect(UI::UILevelSelect["button_start"], YELLOW);
    Render::drawText("Start", UI::UILevelSelect["text_start"]);
}

void SceneLevelSelect::mouseUp(Game& game, Vector2 pos) {
    for (int i = 0; i < 15; i++) {
        int col = i % 5;
        int row = (i - col) / 5;
        std::array<float, 6> rect = {
            UI::UILevelSelect["button_level"][0] + UI::UILevelSelect["button_level"][2] * col,
            UI::UILevelSelect["button_level"][1] + UI::UILevelSelect["button_level"][3] * row,
            UI::UILevelSelect["button_level"][4], UI::UILevelSelect["button_level"][5]
        };

        if (Util::pointInsideRectUI(pos, rect)) {
            selectedLevel = i;
        }
    }

    if (Util::pointInsideRectUI(pos, UI::UILevelSelect["button_back"])) {
        game.changeSceneTo(TITLE);
    }

    if (Util::pointInsideRectUI(pos, UI::UILevelSelect["button_prev"])) {
        if (page > 0) page -= 1;
    } else if (Util::pointInsideRectUI(pos, UI::UILevelSelect["button_next"])) {
        if (page < 7) page += 1;
    } else if (Util::pointInsideRectUI(pos, UI::UILevelSelect["button_start"])) {
        if (selectedLevel != -1) {
            game.selectedLevel = page * 15 + selectedLevel + 1;
            game.changeSceneTo(BATTLE);
            game.state = READY;
        }
    }
}
