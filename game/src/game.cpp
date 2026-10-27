#include "game.hpp"
#include "scene.hpp"
#include "asset.hpp"

Game::Game() {
    #ifdef __EMSCRIPTEN__
    InitWindow(logicWidth, logicHeight, "Planterguy Defense");
    #else
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(logicWidth, logicHeight, "Planterguy Defense");
    #ifndef __APPLE__
    int width, height;
    Vector2 scale = GetWindowScaleDPI();
    width = (int)(logicWidth * scale.x);
    height = (int)(logicHeight * scale.y);
    SetWindowSize(width, height);
    #endif
    SetExitKey(KEY_NULL);
    #endif

    Asset::loadAsset();

    scenes = {
        {TITLE, make_shared<SceneTitle>()},
        {LEVEL_SELECT, make_shared<SceneLevelSelect>()},
        {ADVENTURE_SELECT, make_shared<SceneAdventureSelect>()},
        {BATTLE, make_shared<SceneBattle>()},
    };
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

        scene->mouseUp(*this, pos);
    }
}

void Game::changeSceneTo(int targetScene) {
    scene = scenes[targetScene];
    scene->ready(*this);
}
