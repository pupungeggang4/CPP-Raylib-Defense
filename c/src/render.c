#include "render.h"

void drawText(const char* text, Vector2 pos, int size, Color color) {
    DrawTextEx(GetFontDefault(), text, pos, size, size / 10.0f, color);
}

void drawRect(Rectangle rect, Color color) {
    DrawRectangleRec(rect, color);
}

void drawTexture(Texture2D texture, Rectangle rect) {
    Vector2 pos = {rect.x, rect.x};
    DrawTextureV(texture, pos, WHITE);
}
