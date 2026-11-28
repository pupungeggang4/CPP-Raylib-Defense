#include "asset.h"

Asset asset = {0};

void assetLoad(Asset* asset) {
    asset->texture[T_BACK] = LoadTexture("asset/image/button_back.png");
    asset->texture[T_MENU] = LoadTexture("asset/image/button_menu.png");
}

void assetDispose(Asset* asset) {
    for (int i = 0; i < 256; i++) {
        if (asset->texture[i].id > 0) {
            UnloadTexture(asset->texture[i]);
        }
    }
}
