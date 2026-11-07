#include "game.hpp"
#include "scene.hpp"
#include "asset.hpp"

Game::Game() {
    #ifdef __EMSCRIPTEN__
    InitWindow(logicWidth, logicHeight, "Planterguy Defense");
    #else
    float aspRatio = 0.75;
    SetConfigFlags(FLAG_VSYNC_HINT);
    int width = 800, height = 600;
    InitWindow(width, height, "Planterguy Defense");
    int mWidth = GetMonitorWidth(0); int mHeight = GetMonitorHeight(0);
    if (mWidth * aspRatio > height) {
        height = (int)(mHeight * 0.8); width = (int)(height / aspRatio);
    } else {
        width = (int)(mWidth * 0.8); height = (int)(width * aspRatio);
    }
    SetWindowSize(width, height);
    SetWindowPosition((mWidth - width) / 2, (mHeight - height) / 2);
    Camera2D tempCamera = {0}; camera = tempCamera;

    SetExitKey(KEY_NULL);
    SetWindowIcon(Asset::icon);
    #endif

    Asset::loadAsset();

    scenes = {
        {TITLE, make_shared<SceneTitle>()},
        {LEVEL_SELECT, make_shared<SceneLevelSelect>()},
        {BATTLE, make_shared<SceneBattle>()},
        {COLLECTION, make_shared<SceneCollection>()}
    };

    scenes.emplace(TITLE, make_shared<SceneTitle>());
    scene = scenes[TITLE];
    scene->ready(*this);
}

void Game::loop() {
    camera.zoom = GetRenderWidth() / 800.0f;
    inputHandle();
    scene->update(*this);

    BeginDrawing();
    BeginMode2D(camera);
    ClearBackground(WHITE);
    scene->render(*this);
    EndMode2D();
    EndDrawing();

    if (queueSceneChange != -1) {
        try {
            scene = scenes[queueSceneChange];
            scene->ready(*this);
            queueSceneChange = -1;
        } catch (...) {
            running = false;
        }
    }

    if (WindowShouldClose()) {
        running = false;
    }
}

void Game::inputHandle() {
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        Vector2 pos = GetMousePosition();
        pos = Vector2Scale(pos, 1 / camera.zoom);
        std::cout << pos.x << ' ' << pos.y << std::endl;

        scene->mouseUp(*this, pos);
    }
}

void Game::changeSceneTo(int targetScene) {
    queueSceneChange = targetScene;
}
