#ifndef GAMEVAR_H
#define GAMEVAR_H

#include "includes.h"
#include "types.h"

struct GameVar {
    int running; float dt;
    int width; int height; float aspRatio;
    int scene; int sceneNext; int state; int menu;
    Camera2D camera;
};

extern GameVar gameVar;

#endif
