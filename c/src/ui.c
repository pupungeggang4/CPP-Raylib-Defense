#include "ui.h"

UITitle uiTitle = {
    {20, 20}, // textTitle
    {160, 160, 480, 80}, // buttonStart
    {180, 180}, // textStart
    {160, 240, 480, 80}, // buttonSurvival
    {180, 260}, // textSurvival
    {160, 320, 480, 80}, // buttonErase
    {180, 340} // textErase
};

UILevelSelect uiLevelSelect = {
    {20, 20}, // textTitle
    {740, 20, 40, 40}, // buttonBack
    {60, 80}, // buttonLevelStart
    {120, 120}, // buttonLevelSize
    {140, 140}, // buttonLevelStep
    {10, 10} // textLevel
};

UIBattle uiBattle = {
    {740, 20, 40, 40} // buttonMenu
};

UIMenu uiMenu = {
    {160, 140, 480, 320}, // rect
    {180, 160}, // textPaused
    {160, 220, 480, 80}, // buttonResume
    {180, 240}, // textResume
    {160, 300, 480, 80}, // buttonExit
    {180, 320}, // textExit
    {160, 380, 480, 80}, // buttonQuit
    {180, 400} // textQuit
};
