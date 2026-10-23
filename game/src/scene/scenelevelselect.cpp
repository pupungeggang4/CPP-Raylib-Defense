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
}

void SceneLevelSelect::mouseUp(Game& game, Vector2 pos) {
    if (Util::pointInsideRectUI(pos, UI::UILevelSelect["button_back"])) {
        game.changeSceneTo(TITLE);
    }
}
