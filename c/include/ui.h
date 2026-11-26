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
};

struct UIBattleWindow {

};

struct UIMenu {
    
};

extern UITitle uiTitle;
extern UILevelSelect uiLevelSelect;
extern UIBattle uiBattle;
extern UIBattleWindow uiBattleWindow;
extern UIMenu uiMenu;

#endif
