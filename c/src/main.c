#include "includes.h"
#include "game.h"
#include "gamevar.h"

int main(int argc, char** argv) {
    gameInit(&gameVar);
    while (gameVar.running) {
        gameLoop(&gameVar);
    }
    gameEnd();
    return 0;
}
