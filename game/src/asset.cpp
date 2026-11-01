#include "asset.hpp"

std::unordered_map<std::string, Texture2D> Asset::texture = {};
Image Asset::icon;

void Asset::loadAsset() {
    icon = LoadImage("asset/icon.png");
    texture.emplace("arrow", LoadTexture("asset/image/arrow.png"));
    texture.emplace("button_menu", LoadTexture("asset/image/button_menu.png"));
    texture.emplace("button_back", LoadTexture("asset/image/button_back.png"));
    texture.emplace("collection", LoadTexture("asset/image/collection.png"));
}

void Asset::disposeAsset() {
    UnloadImage(icon);
    for (auto& pair: texture) {
        UnloadTexture(pair.second);
    }
}
