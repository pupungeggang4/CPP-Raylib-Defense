#include "scene.hpp"

#include "asset.hpp"
#include "ui.hpp"

#include "util.hpp"
#include "render.hpp"

#include "game.hpp"

SceneLevelSelect::SceneLevelSelect() {

}

void SceneLevelSelect::ready(Game& game) {
}

void SceneLevelSelect::update(Game& game) {
}

void SceneLevelSelect::render(Game& game) {
    Render::drawText("Select Level", UI::UILevelSelect["text_title"]);
    Render::drawTexture(Asset::texture["button_menu"], UI::UILevelSelect["button_back"]);

    for (int i = 0; i < 15; i++) {
        int col = i % 5;
        int row = (i - col) / 5;
        std::vector<float> rect = {
            UI::UILevelSelect["button_level"][0] + UI::UILevelSelect["button_level"][2] * col,
            UI::UILevelSelect["button_level"][1] + UI::UILevelSelect["button_level"][3] * row,
            UI::UILevelSelect["button_level"][4], UI::UILevelSelect["button_level"][5]
        };
        Render::drawRect(rect, YELLOW);
        std::vector<float> pos = {rect[0] + 20, rect[1] + 20};
        Render::drawText(TextFormat("%d", i + 1), pos);
    }

    Render::drawRect(UI::UILevelSelect["button_start"], YELLOW);
    Render::drawText("Start", UI::UILevelSelect["text_start"]);
}

void SceneLevelSelect::mouseUp(Game& game, Vector2 pos) {
    if (Util::pointInsideRectUI(pos, UI::UILevelSelect["button_back"])) {
        game.changeSceneTo(TITLE);
    }
}
