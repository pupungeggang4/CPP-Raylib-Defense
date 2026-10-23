#include "asset.hpp"

std::unordered_map<std::string, Texture2D> Asset::texture = {};

void Asset::loadAsset() {
    texture.emplace("arrow", LoadTexture("asset/arrow.png"));
    texture.emplace("button_menu", LoadTexture("asset/button_menu.png"));
}

void Asset::disposeAsset() {
    for (auto& pair: texture) {
        UnloadTexture(pair.second);
    }
}
