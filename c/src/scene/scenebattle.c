#include "scene.h"

#include "asset.h"
#include "ui.h"
#include "render.h"

#include "gamevar.h"

void sceneBattleReady(GameVar* gameVar) {

}

void sceneBattleUpdate(GameVar* gameVar) {

}

void sceneBattleRender(GameVar* gameVar) {
    drawTexture(asset.texture[T_MENU], uiBattle.buttonMenu);

    if (gameVar->state == ST_START) sceneWindowStartRender(gameVar);

    if (gameVar->menu) {
        sceneMenuRender(gameVar);
    }
}

void sceneBattleMouseUp(GameVar* gameVar, Vector2 pos, int button) {
    if (button == LEFT) {
        if (gameVar->menu) {
            sceneMenuMouseUp(gameVar, pos, button);
            if (CheckCollisionPointRec(pos, uiBattle.buttonMenu)) gameVar->menu = FALSE;
        } else {
            if (CheckCollisionPointRec(pos, uiBattle.buttonMenu)) gameVar->menu = TRUE;
            if (gameVar->state == ST_START) sceneWindowStartMouseUp(gameVar, pos, button);
        }
    }
}
