#ifndef GAME_HPP
#define GAME_HPP

#include "includes.hpp"

class Game {
    public:
        // System var
        int width, height, logicWidth, logicHeight;
        float scale = 0;

        // Game system var
        int state = NORMAL;
        bool menu = false;
        bool running = true;

        // Game var


        Game();
        void loop();
        void inputHandle();
};

#endif
