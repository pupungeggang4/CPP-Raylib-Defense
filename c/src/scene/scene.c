#include "scene.h"

void (*sceneReadys[])(GameVar*) = {sceneTitleReady, sceneLevelSelectReady};
void (*sceneUpdates[])(GameVar*) = {sceneTitleUpdate, sceneLevelSelectUpdate};
void (*sceneRenders[])(GameVar*) = {sceneTitleRender, sceneLevelSelectRender};
void (*sceneMouseUps[])(GameVar*, Vector2, int) = {sceneTitleMouseUp, sceneLevelSelectMouseUp};
