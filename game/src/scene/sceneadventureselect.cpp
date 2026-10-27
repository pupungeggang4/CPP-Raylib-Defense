#include "scene.hpp"

#include "asset.hpp"
#include "ui.hpp"

#include "util.hpp"
#include "render.hpp"

#include "game.hpp"

SceneAdventureSelect::SceneAdventureSelect() {
    
}

void SceneAdventureSelect::ready(Game& game) {
    selectedCharacter = -1;
}

void SceneAdventureSelect::update(Game& game) {
}

void SceneAdventureSelect::render(Game& game) {
    Render::drawText("Select Character", UI::UIAdventureSelect["text_title"]);
    Render::drawTexture(Asset::texture["button_back"], UI::UIAdventureSelect["button_back"]);

    for (int i = 0; i < 6; i++) {
        int col = i % 3;
        int row = (i - col) / 3;
        std::array<float, 6> rect = {
            UI::UIAdventureSelect["button_character"][0] + UI::UIAdventureSelect["button_character"][2] * col,
            UI::UIAdventureSelect["button_character"][1] + UI::UIAdventureSelect["button_character"][3] * row,
            UI::UIAdventureSelect["button_character"][4], UI::UIAdventureSelect["button_character"][5]
        };

        if (i != selectedCharacter) {
            Render::drawRect(rect, YELLOW);
        } else {
            Render::drawRect(rect, GREEN);
        }
    }

    Render::drawRect(UI::UIAdventureSelect["description_area"], YELLOW);

    Render::drawRect(UI::UIAdventureSelect["button_start"], YELLOW);
    Render::drawText("Start", UI::UIAdventureSelect["text_start"]);
}

void SceneAdventureSelect::mouseUp(Game& game, Vector2 pos) {
    if (Util::pointInsideRectUI(pos, UI::UIAdventureSelect["button_back"])) {
        game.changeSceneTo(TITLE);
    }

    for (int i = 0; i < 6; i++) {
        int col = i % 3;
        int row = (i - col) / 3;
        std::array<float, 6> rect = {
            UI::UIAdventureSelect["button_character"][0] + UI::UIAdventureSelect["button_character"][2] * col,
            UI::UIAdventureSelect["button_character"][1] + UI::UIAdventureSelect["button_character"][3] * row,
            UI::UIAdventureSelect["button_character"][4], UI::UIAdventureSelect["button_character"][5]
        };
        
        if (Util::pointInsideRectUI(pos, rect)) {
            selectedCharacter = i;
        }
    }

    if (Util::pointInsideRectUI(pos, UI::UIAdventureSelect["button_start"])) {
        if (selectedCharacter != -1) {
            game.changeSceneTo(BATTLE);
        }
    }
}
