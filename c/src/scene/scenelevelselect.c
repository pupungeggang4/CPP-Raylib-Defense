#include "scene.h"

#include "ui.h"
#include "render.h"

#include "gamevar.h"

void sceneLevelSelectReady(GameVar* gameVar) {

}

void sceneLevelSelectUpdate(GameVar* gameVar) {

}

void sceneLevelSelectRender(GameVar* gameVar) {
    drawText("Select Level", uiLevelSelect.textTitle, 20, BLACK);
    drawRect(uiLevelSelect.buttonBack, BLUE);

    for (int i = 0; i < 15; i++) {
        int col = i % 5;
        int row = (i - col) / 5;
        Rectangle rect = {
            uiLevelSelect.buttonLevelStart.x + uiLevelSelect.buttonLevelStep.x * col,
            uiLevelSelect.buttonLevelStart.y + uiLevelSelect.buttonLevelStep.y * row,
            uiLevelSelect.buttonLevelSize.x, uiLevelSelect.buttonLevelSize.y
        };
        drawRect(rect, YELLOW);
        Vector2 pos = {rect.x + uiLevelSelect.textLevel.x, rect.y + uiLevelSelect.textLevel.y};
        char buf[10];
        snprintf(buf, sizeof(buf), "%d", i + 1);
        drawText(buf, pos, 20, BLACK);
    }
}

void sceneLevelSelectMouseUp(GameVar* gameVar, Vector2 pos, int button) {
    if (button == LEFT) {
        if (CheckCollisionPointRec(pos, uiLevelSelect.buttonBack)) gameVar->sceneNext = S_TITLE;

        for (int i = 0; i < 15; i++) {
            int col = i % 5;
            int row = (i - col) / 5;
            Rectangle rect = {
                uiLevelSelect.buttonLevelStart.x + uiLevelSelect.buttonLevelStep.x * col,
                uiLevelSelect.buttonLevelStart.y + uiLevelSelect.buttonLevelStep.y * row,
                uiLevelSelect.buttonLevelSize.x, uiLevelSelect.buttonLevelSize.y
            };
            if (CheckCollisionPointRec(pos, rect)) gameVar->sceneNext = S_BATTLE;
        }
    }
}
