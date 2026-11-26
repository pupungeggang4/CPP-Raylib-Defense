#include "scene.h"

void (*sceneReadys[])(GameVar*) = {sceneTitleReady, sceneLevelSelectReady, sceneBattleReady};
void (*sceneUpdates[])(GameVar*) = {sceneTitleUpdate, sceneLevelSelectUpdate, sceneBattleUpdate};
void (*sceneRenders[])(GameVar*) = {sceneTitleRender, sceneLevelSelectRender, sceneBattleRender};
void (*sceneMouseUps[])(GameVar*, Vector2, int) = {sceneTitleMouseUp, sceneLevelSelectMouseUp, sceneBattleMouseUp};
