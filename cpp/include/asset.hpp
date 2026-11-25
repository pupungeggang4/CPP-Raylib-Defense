#ifndef ASSET_HPP
#define ASSET_HPP

#include "includes.hpp"

class Asset {
    public:
        static Image icon;
        static std::unordered_map<std::string, Texture2D> texture;

        static void loadAsset();
        static void disposeAsset();
};

#endif
