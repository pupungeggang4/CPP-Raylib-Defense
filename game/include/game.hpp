#ifndef GAME_HPP
#define GAME_HPP

#include "includes.hpp"

class Scene;

class Game {
    public:
        // System var
        int width, height, logicWidth = 800, logicHeight = 600;
        float scale = 0;

        // Game system var
        std::unordered_map<int, shared_ptr<Scene>> scenes;
        shared_ptr<Scene> scene;

        int state = NORMAL;
        bool menu = false;
        bool running = true;

        // Game var
        
        // Function
        Game();
        void loop();
        void inputHandle();
        void changeSceneTo(int);
};

#endif
