#ifndef TYPES_H
#define TYPES_H

enum Tex {T_BACK, T_MENU};
enum Boolean {FALSE, TRUE};
enum Direction {LEFT, RIGHT, UP, DOWN};
enum SceneName {S_TITLE, S_LEVEL_SELECT, S_BATTLE};
enum SceneState {ST_NORMAL, ST_START};
enum GameMode {CLASSIC, SURVIVAL};

typedef struct Asset Asset;

typedef struct UITitle UITitle;
typedef struct UILevelSelect UILevelSelect;
typedef struct UIBattle UIBattle;
typedef struct UIWindowStart UIWindowStart;
typedef struct UIWindowReward UIWindowReward;
typedef struct UIMenu UIMenu;

typedef struct SceneLevelSelectVar SceneLevelSelectVar;
typedef struct SceneBattleVar SceneBattleVar;
typedef struct GameVar GameVar;

#endif
