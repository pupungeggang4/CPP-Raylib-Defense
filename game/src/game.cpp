#include "game.hpp"

Game::Game() {
    InitWindow(800, 600, "Planterguy Defense");

    int width, height;
    int currentMonitor = GetCurrentMonitor();
    int monitorWidth = GetMonitorWidth(currentMonitor);
    int monitorHeight = GetMonitorHeight(currentMonitor);

    if (monitorWidth * 3 > monitorHeight * 4) {
        height = monitorHeight * 0.8f; width = height * 4 / 3;
    } else {
        width = monitorWidth * 0.8f; height = width * 3 / 4;
    }

    SetTargetFPS(60);
    SetExitKey(KEY_NULL);
    SetWindowSize(width, height);
    SetWindowPosition((monitorWidth - width) / 2, (monitorHeight - height) / 2);
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
