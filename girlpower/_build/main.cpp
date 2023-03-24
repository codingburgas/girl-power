#include "main.h"
#include "resizableScreen.h"

int main()
{
    int screenWidth = 800, screenHeight = 450;
    float roundness = 0.2f;
    bool drawRoundedRect = true;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "main");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        DrawRectangle(screenWidth / 4 * 2 - 333, 100, 550, 300, RED);
        roundness = GuiSliderBar((Rectangle) { 640, 140, 105, 20 }, "Roundness", NULL, roundness, 0.0f, 1.0f);
        EndDrawing();
    }

    CloseWindow();
}
// maika mu she eba 