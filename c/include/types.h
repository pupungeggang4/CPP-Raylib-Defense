#ifndef TYPES_H
#define TYPES_H

enum Boolean {FALSE, TRUE};
enum Direction {LEFT, RIGHT, UP, DOWN};
enum SceneName {S_TITLE, S_LEVEL_SELECT, S_BATTLE};
enum SceneState {ST_NORMAL, ST_READY};

typedef struct UITitle UItitle;
typedef struct UILevelSelect UILevelSelect;
typedef struct UIField UIField;

typedef struct SceneLevelSelectVar SceneLevelSelectVar;
typedef struct SceneBattleVar SceneBattleVar;
typedef struct GameVar GameVar;

#endif
