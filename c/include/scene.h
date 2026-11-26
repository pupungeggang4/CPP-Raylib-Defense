#ifndef SCENE_H
#define SCENE_H

#include "includes.h"
#include "types.h"

void sceneTitleReady(GameVar*);
void sceneTitleUpdate(GameVar*);
void sceneTitleRender(GameVar*);
void sceneTitleMouseUp(GameVar*, Vector2, int);

void sceneLevelSelectReady(GameVar*);
void sceneLevelSelectUpdate(GameVar*);
void sceneLevelSelectRender(GameVar*);
void sceneLevelSelectMouseUp(GameVar*, Vector2, int);

void sceneBattleReady(GameVar*);
void sceneBattleUpdate(GameVar*);
void sceneBattleRender(GameVar*);
void sceneBattleMouseUp(GameVar*, Vector2, int);

void sceneMenuReady(GameVar*);
void sceneMenuUpdate(GameVar*);
void sceneMenuRender(GameVar*);
void sceneMenuMouseUp(GameVar*, Vector2, int);

extern void (*sceneReadys[])(GameVar*);
extern void (*sceneUpdates[])(GameVar*);
extern void (*sceneRenders[])(GameVar*);
extern void (*sceneMouseUps[])(GameVar*, Vector2, int);

#endif
