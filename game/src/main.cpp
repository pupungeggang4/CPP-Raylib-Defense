#include "includes.hpp"
#include "game.hpp"
#include "asset.hpp"

int main(int argc, char** argv) {
    Game game;
    while (game.running) {
        game.loop();
    }
    Asset::disposeAsset();
    CloseWindow();
    return 0;
}
