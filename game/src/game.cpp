#include "game.hpp"

Game::Game() {
    #ifdef __EMSCRIPTEN__
    InitWindow(800, 600, "Planterguy Defense");
    #else
    InitWindow(800, 600, "Planterguy Defense");
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    #ifndef __APPLE__
    int width, height;
    Vector2 scale = GetWindowScaleDPI();
    width = (int)(800.0f * scale.x);
    height = (int)(600.0f * scale.y);
    SetWindowSize(width, height);
    SetWindowPosition(48, 48);
    #endif
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);
    #endif
}

void Game::loop() {
    camera.zoom = GetRenderWidth() / 800.0f;

    inputHandle();

    BeginDrawing();
    ClearBackground(WHITE);
    EndDrawing();

    if (WindowShouldClose()) {
        running = false;
    }
}

void Game::inputHandle() {
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        Vector2 pos = GetScreenToWorld2D(Vector2Scale(GetMousePosition(), GetWindowScaleDPI().x), camera);
        std::cout << pos.x << ' ' << pos.y << std::endl;
    }
}
