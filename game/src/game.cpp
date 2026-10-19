#include "game.hpp"
#include "scene.hpp"

Game::Game() {
    #ifdef __EMSCRIPTEN__
    InitWindow(800, 600, "Planterguy Defense");
    #else
    InitWindow(800, 600, "Planterguy Defense");
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    SetConfigFlags(FLAG_VSYNC_HINT);
    #ifndef __APPLE__
    int width, height;
    Vector2 scale = GetWindowScaleDPI();
    width = (int)(800.0f * scale.x);
    height = (int)(600.0f * scale.y);
    SetWindowSize(width, height);
    SetWindowPosition(48, 48);
    #endif
    SetExitKey(KEY_NULL);
    #endif

    scenes = {};
    scenes.emplace(TITLE, make_shared<SceneTitle>());
    scene = scenes[TITLE];
    scene->ready(*this);
}

void Game::loop() {
    inputHandle();
    scene->update(*this);

    BeginDrawing();
    ClearBackground(WHITE);
    scene->render(*this);
    EndDrawing();

    if (WindowShouldClose()) {
        running = false;
    }
}

void Game::inputHandle() {
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        Vector2 pos = GetMousePosition();
        std::cout << pos.x << ' ' << pos.y << std::endl;
    }
}
