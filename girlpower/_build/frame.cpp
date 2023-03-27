#include "pch.h"

void printFrame(const int screenWidth, const int screenHeight)
{
		ClearBackground(DARKBLUE3);
        Font Bubble = LoadFontEx("assets/fonts/Designer.ttf", 108, NULL, 0);
        SetTextureFilter(Bubble.texture, TEXTURE_FILTER_BILINEAR);
        DrawTextEx(Bubble, "C", Vector2{ 300, 100 }, 96, 0.0f, RAYWHITE);
        DrawTextEx(Bubble, "I", Vector2{ 300, 100 }, 96, 0.0f, RAYWHITE);
        DrawTextEx(Bubble, "P", Vector2{ 300, 100 }, 96, 0.0f, RAYWHITE);
        DrawTextEx(Bubble, "H", Vector2{ 300, 100 }, 96, 0.0f, RAYWHITE);
        DrawTextEx(Bubble, "E", Vector2{ 300, 100 }, 96, 0.0f, RAYWHITE);
        DrawTextEx(Bubble, "R", Vector2{ 300, 100 }, 96, 0.0f, RAYWHITE);
        //should be switched to gradient class
}