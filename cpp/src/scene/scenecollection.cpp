#include "scene.hpp"
#include "ui.hpp"
#include "asset.hpp"
#include "util.hpp"
#include "render.hpp"
#include "game.hpp"

SceneCollection::SceneCollection() {
}

void SceneCollection::ready(Game& game) {
}

void SceneCollection::update(Game& game) {
}

void SceneCollection::render(Game& game) {
    Render::drawText("Collection", UI::UICollection["text_title"]);
    Render::drawTexture(Asset::texture["button_back"], UI::UICollection["button_back"]);
}

void SceneCollection::mouseUp(Game& game, Vector2 pos) {
    if (Util::pointInsideRectUI(pos, UI::UICollection["button_back"])) game.changeSceneTo(TITLE);
}
