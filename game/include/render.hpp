#ifndef RENDER_HPP
#define RENDER_HPP

#include "includes.hpp"

class Render {
    public:
        static void drawRect(std::array<float, 6>&, Color = BLACK);
        static void drawText(std::string, std::array<float, 6>&, int size = 20, Color color = BLACK);
        static void drawTexture(Texture2D, std::array<float, 6>&);
};

#endif
