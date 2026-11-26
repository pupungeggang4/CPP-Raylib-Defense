#ifndef TYPES_H
#define TYPES_H

enum Boolean {FALSE, TRUE};
enum Direction {LEFT, RIGHT, UP, DOWN};
enum SceneName {S_TITLE, S_LEVEL_SELECT, S_BATTLE};
enum SceneState {ST_NORMAL, ST_READY};

typedef struct UITitle UITitle;
typedef struct UILevelSelect UILevelSelect;
typedef struct UIBattle UIBattle;
typedef struct UIBattleWindow UIBattleWindow;
typedef struct UIMenu UIMenu;

typedef struct SceneLevelSelectVar SceneLevelSelectVar;
typedef struct SceneBattleVar SceneBattleVar;
typedef struct GameVar GameVar;

#endif
