#include "scene.hpp"
#include "ui.hpp"
#include "asset.hpp"
#include "util.hpp"
#include "render.hpp"
#include "game.hpp"

SceneBattle::SceneBattle() {
    menu = make_shared<Menu>();
}

void SceneBattle::ready(Game& game) {
}

void SceneBattle::update(Game& game) {
}

void SceneBattle::render(Game& game) {
    Render::drawTexture(Asset::texture["button_menu"], UI::UIBattle["button_menu"]);

    if (game.menu) {
        menu->render(game);
    }
}

void SceneBattle::mouseUp(Game& game, Vector2 pos) {
    if (game.menu) {
        menu->mouseUp(game, pos);
        if (Util::pointInsideRectUI(pos, UI::UIBattle["button_menu"])) game.menu = false;
    } else {
        if (Util::pointInsideRectUI(pos, UI::UIBattle["button_menu"])) game.menu = true;
    }
}
