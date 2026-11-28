#include "scene.h"

#include "ui.h"
#include "gamevar.h"

#include "render.h"

void sceneWindowStartReady(GameVar* gameVar) {

}

void sceneWindowStartUpdate(GameVar* gameVar) {
    
}

void sceneWindowStartRender(GameVar* gameVar) {
    drawRect(uiWindowStart.rect, YELLOW);
    if (gameVar->mode == CLASSIC) {
        drawText("Ready for Battle", uiWindowStart.textTitle, 20, BLACK);
    } else {
        drawText("Select", uiWindowStart.textTitle, 20, BLACK);
    }
    drawRect(uiWindowStart.buttonStart, PINK);
    drawText("Start", uiWindowStart.textStart, 20, BLACK);
}

void sceneWindowStartMouseUp(GameVar* gameVar, Vector2 pos, int button) {
    if (CheckCollisionPointRec(pos, uiWindowStart.buttonStart)) {
        gameVar->state = ST_NORMAL;
    }
}
