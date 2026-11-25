#include "game.h"
#include "gamevar.h"

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
    gameVar->running = TRUE;
    Camera2D tempCamera = {0}; gameVar->camera = tempCamera;
}

void gameLoop(GameVar* gameVar) {
    gameVar->camera.zoom = (float)(GetRenderWidth()) / gameVar->width;
    gameVar->dt = GetFrameTime();

    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode2D(gameVar->camera);
    EndMode2D();
    EndDrawing();

    if (WindowShouldClose()) gameVar->running = FALSE;
}

void gameEnd() {
    CloseWindow();
}
