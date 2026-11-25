#include "scene.hpp"
#include "ui.hpp"
#include "asset.hpp"
#include "util.hpp"
#include "render.hpp"
#include "game.hpp"

Menu::Menu() {

}

void Menu::ready(Game& game) {
}

void Menu::render(Game& game) {
    Render::drawRect(UI::UIMenu["rect"], BLUE);
    Render::drawText("Paused", UI::UIMenu["text_paused"]);
    Render::drawRect(UI::UIMenu["button_resume"], YELLOW);
    Render::drawText("Resume", UI::UIMenu["text_resume"]);
    Render::drawRect(UI::UIMenu["button_exit"], PINK);
    Render::drawText("Exit", UI::UIMenu["text_exit"]);
    Render::drawRect(UI::UIMenu["button_quit"], YELLOW);
    Render::drawText("Quit", UI::UIMenu["text_quit"]);
}

void Menu::mouseUp(Game& game, Vector2 pos) {
    if (Util::pointInsideRectUI(pos, UI::UIMenu["button_resume"])) {
        game.menu = false;
    } else if (Util::pointInsideRectUI(pos, UI::UIMenu["button_exit"])) {
        game.menu = false;
        game.changeSceneTo(TITLE);
    } else if (Util::pointInsideRectUI(pos, UI::UIMenu["button_quit"])) {
        game.running = false;
    }
}
