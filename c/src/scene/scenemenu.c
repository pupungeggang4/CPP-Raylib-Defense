#include "scene.h"

#include "ui.h"
#include "render.h"

#include "gamevar.h"

void sceneMenuReady(GameVar* gameVar) {

}

void sceneMenuUpdate(GameVar* gameVar) {

}

void sceneMenuRender(GameVar* gameVar) {
    drawRect(uiMenu.rect, YELLOW);
    drawText("Paused", uiMenu.textPaused, 20, BLACK);
    drawRect(uiMenu.buttonResume, PINK);
    drawText("Resume", uiMenu.textResume, 20, BLACK);
    drawRect(uiMenu.buttonExit, YELLOW);
    drawText("Exit to Title", uiMenu.textExit, 20, BLACK);
    drawRect(uiMenu.buttonQuit, PINK);
    drawText("Quit Game", uiMenu.textQuit, 20, BLACK);
}

void sceneMenuMouseUp(GameVar* gameVar, Vector2 pos, int button) {
    if (CheckCollisionPointRec(pos, uiMenu.buttonResume)) {
        gameVar->menu = FALSE;
    } else if (CheckCollisionPointRec(pos, uiMenu.buttonExit)) {
        gameVar->menu = FALSE;
        gameVar->sceneNext = S_TITLE;
    } else if (CheckCollisionPointRec(pos, uiMenu.buttonQuit)) gameVar->running = FALSE;
}
