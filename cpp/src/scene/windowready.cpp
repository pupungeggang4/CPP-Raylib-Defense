#include "scene.hpp"
#include "ui.hpp"
#include "asset.hpp"
#include "util.hpp"
#include "render.hpp"
#include "game.hpp"

WindowReady::WindowReady() {

}

void WindowReady::ready(Game& game) {
}

void WindowReady::render(Game& game) {
    Render::drawRect(UI::UIWindowReady["rect"], YELLOW);
    Render::drawText("Ready", UI::UIWindowReady["text_title"]);
    Render::drawRect(UI::UIWindowReady["button_start"], PINK);
    Render::drawText("Start", UI::UIWindowReady["text_start"]);
}

void WindowReady::mouseUp(Game& game, Vector2 pos) {
    if (Util::pointInsideRectUI(pos, UI::UIWindowReady["button_start"])) {
        game.state = NORMAL;
    }
}
