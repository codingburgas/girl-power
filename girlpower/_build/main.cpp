#include "pch.h"
using namespace std;

int main()
{
    const int screenWidth = 1720;
    const int screenHeight = 900;
    int framesCounter = 0;
    int letterCounter = 0;
    float roundnessTextBox = 0.5f;
    bool mouseOnText = false;
    float roundnessMain = 0.1f;

    /*SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);*/

    InitWindow(screenWidth, screenHeight, "cipher");
    mainMenuLoop(screenWidth, framesCounter, letterCounter, roundnessMain, roundnessTextBox, mouseOnText);
    //input box window 

    SetTargetFPS(10);

    /*while (!WindowShouldClose())
    {
        if (inputPrint(mouseOnText) == true)
        {
            Active(framesCounter, letterCounter);
        }
        else
        {
            nonActive(framesCounter);
        }

        BeginDrawing();
        drawInput(screenWidth, framesCounter, letterCounter, roundnessTextBox, roundnessMain);
        EndDrawing();
    } CloseWindow();
    float timePlayed = 0.0f;
    float roundness = 0.5f;
    LoadingLoop(timePlayed, roundness);*/
}
// maika mu she eba 