#include "scene.h"

#include "ui.h"
#include "render.h"

#include "gamevar.h"

void sceneTitleReady(GameVar* gameVar) {

}

void sceneTitleUpdate(GameVar* gameVar) {

}

void sceneTitleRender(GameVar* gameVar) {
    drawText("Planterguy Defense", uiTitle.textTitle, 20, BLACK);
    drawRect(uiTitle.buttonStart, YELLOW);
    drawText("Start Game", uiTitle.textStart, 20, BLACK);
    drawRect(uiTitle.buttonSurvival, PINK);
    drawText("Survival", uiTitle.textSurvival, 20, BLACK);
    drawRect(uiTitle.buttonQuit, YELLOW);
    drawText("Quit Game", uiTitle.textQuit, 20, BLACK);
}

void sceneTitleMouseUp(GameVar* gameVar, Vector2 pos, int button) {
    if (button == LEFT) {
        if (CheckCollisionPointRec(pos, uiTitle.buttonStart)) gameVar->sceneNext = S_LEVEL_SELECT;
        if (CheckCollisionPointRec(pos, uiTitle.buttonQuit)) gameVar->running = FALSE;
    }
}
