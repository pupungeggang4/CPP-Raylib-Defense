#include "scene.hpp"
#include "ui.hpp"
#include "render.hpp"
#include "game.hpp"

SceneTitle::SceneTitle() {
}

void SceneTitle::ready(Game& game) {
}

void SceneTitle::update(Game& game) {
}

void SceneTitle::render(Game& game) {
    Render::drawText("Planterguy Defense", UI::UITitle["title"]);
    Render::drawRect(UI::UITitle["button_start"], YELLOW);
    Render::drawText("Start Game", UI::UITitle["text_start"]);
    Render::drawRect(UI::UITitle["button_erase"], PINK);
}
