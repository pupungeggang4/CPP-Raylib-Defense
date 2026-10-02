#ifndef GAME_HPP
#define GAME_HPP

#include "includes.hpp"

class Game {
    public:
        Camera2D camera = {0};

        int state = NORMAL;
        bool running = true;

        Game();
        void loop();
        void inputHandle();
};

#endif
