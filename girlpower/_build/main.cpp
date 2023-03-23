#include "main.h"
#include "resizableScreen.h"

#define DARK CLITERAL(Color){12, 17, 48, 255}
int main()
{
    int screenHeight = 450;
    int screenWidth = 800;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "raylib [core] example - fullscreen toggle");

    SetTargetFPS(60);               
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("pls dont die", 190, 200, 20, DARK);

    } CloseWindow(); 
}
