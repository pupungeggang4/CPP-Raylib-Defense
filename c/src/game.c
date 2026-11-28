#include "game.h"
#include "asset.h"

#include "gamevar.h"

#include "scene.h"

void gameInit(GameVar* gameVar) {
    gameVar->width = 800; gameVar->height = 600; gameVar->aspRatio = 0.75f;
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(gameVar->width, gameVar->height, "Defense Game");
    #ifndef __APPLE__
    int mWidth = GetMonitorWidth(0); int mHeight = GetMonitorHeight(0);
    int wWidth, wHeight;
    if (mWidth * gameVar->aspRatio > mHeight) {
        wHeight = (int)(mHeight * 0.8); wWidth = (int)(wHeight / gameVar->aspRatio);

    } else {
        wWidth = (int)(mWidth * 0.8); wHeight = (int)(wWidth * gameVar->aspRatio);
    }
    SetWindowSize(wWidth, wHeight);
    SetWindowPosition((mWidth - wWidth) / 2, (mHeight - wHeight) / 2);
    #endif
    SetExitKey(KEY_NULL);
    assetLoad(&asset);

    gameVar->running = TRUE;
    gameVar->scene = S_TITLE;
    Camera2D tempCamera = {0}; gameVar->camera = tempCamera;
}

void gameLoop(GameVar* gameVar) {
    gameVar->camera.zoom = (float)(GetRenderWidth()) / gameVar->width;
    gameVar->dt = GetFrameTime();
    gameInputHandle(gameVar);
    sceneUpdates[gameVar->scene](gameVar);
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode2D(gameVar->camera);
    sceneRenders[gameVar->scene](gameVar);
    EndMode2D();
    EndDrawing();

    if (gameVar->sceneNext != -1) {
        gameVar->scene = gameVar->sceneNext;
        sceneReadys[gameVar->scene](gameVar);
        gameVar->sceneNext = -1;
    }
    if (WindowShouldClose()) gameVar->running = FALSE;
}

void gameInputHandle(GameVar* gameVar) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 pos = Vector2Scale(GetMousePosition(), 1 / gameVar->camera.zoom);
        printf("(%.0f, %.0f)\n", pos.x, pos.y);
        sceneMouseUps[gameVar->scene](gameVar, pos, LEFT);
    } else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
        Vector2 pos = Vector2Scale(GetMousePosition(), 1 / gameVar->camera.zoom);
        printf("(%.0f, %.0f)\n", pos.x, pos.y);
        sceneMouseUps[gameVar->scene](gameVar, pos, RIGHT);
    }
}

void gameEnd() {
    assetDispose(&asset);
    CloseWindow();
}
