#include "includes.hpp"
#include "game.hpp"

int main(int argc, char** argv) {
    Game game;
    while (game.running) {
        game.loop();
    }
    CloseWindow();
    return 0;
}
