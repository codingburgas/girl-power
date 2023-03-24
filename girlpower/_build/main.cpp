#include "main.h"
#include "resizableScreen.h"

int main()
{
    int screenWidth = 800, screenHeight = 450;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "raylib [core] example - fullscreen toggle");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        DrawRectangle(screenWidth / 4 * 2 - 333, 100, 550, 300, RED);
        EndDrawing();
    }

    CloseWindow();
}
// maika mu she eba 