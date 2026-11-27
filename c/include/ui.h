#ifndef UI_H
#define UI_H

#include "includes.h"
#include "types.h"

struct UITitle {
    Vector2 textTitle;
    Rectangle buttonStart;
    Vector2 textStart;
    Rectangle buttonSurvival;
    Vector2 textSurvival;
    Rectangle buttonQuit;
    Vector2 textQuit;
};

struct UILevelSelect {
    Vector2 textTitle;
    Rectangle buttonBack;
    Vector2 buttonLevelStart;
    Vector2 buttonLevelSize;
    Vector2 buttonLevelStep;
    Vector2 textLevel;
};

struct UIBattle {
    Rectangle buttonMenu;
};

struct UIWindowStart {
    Rectangle rect;
    Vector2 textTitle;
    Rectangle buttonStart;
    Vector2 textStart;
};

struct UIWindowReward {
    Rectangle rect;
};

struct UIMenu {
    Rectangle rect;
    Vector2 textPaused;
    Rectangle buttonResume;
    Vector2 textResume;
    Rectangle buttonExit;
    Vector2 textExit;
    Rectangle buttonQuit;
    Vector2 textQuit;
};

extern UITitle uiTitle;
extern UILevelSelect uiLevelSelect;
extern UIBattle uiBattle;
extern UIWindowStart uiWindowStart;
extern UIWindowReward uiWindowReward;
extern UIMenu uiMenu;

#endif
