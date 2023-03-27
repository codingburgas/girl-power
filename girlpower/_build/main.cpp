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

    //input box window 

    SetTargetFPS(10);

    ///*while (!WindowShouldClose())
    //{
    //    if (inputPrint(mouseOnText) == true)
    //    {
    //        Active(framesCounter, letterCounter);
    //    }
    //    else
    //    {
    //        nonActive(framesCounter);
    //    }

    //    BeginDrawing();
    //    drawInput(screenWidth, framesCounter, letterCounter, roundnessTextBox, roundnessMain);
    //    EndDrawing();
    //} CloseWindow();*/
    //float timePlayed = 0.0f;
    //float roundness = 0.5f;
    //LoadingLoop(timePlayed, roundness);
    Button playButton;
    playButton.rec = { 700, 251, 319, 109 };
    playButton.state = 0;
    playButton.color = PURPLE2;
    playButton.hoverColor = PURPLE1;

    Button quitButton;
    quitButton.rec = { 700, 421, 319, 109 };
    quitButton.state = 0;
    quitButton.color = PURPLE1;
    quitButton.hoverColor = PURPLE2;

    Font mainFont = LoadFontEx("assets/fonts/Futura.ttf", 54, NULL, 0);
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        mainCipherTemplate(0.1f);

        if (handleButton(playButton, 309, false, true))
        {
                
            if (inputPrint(mouseOnText) == true)
            {
                Active(framesCounter, letterCounter);
            }
            else
            {
                nonActive(framesCounter);
            }
            drawInput(screenWidth, framesCounter, letterCounter, roundnessTextBox, roundnessMain);
        }
            if (handleButton(quitButton, 309, false, true)) return false;

            DrawTextEx(mainFont, "Play", Vector2({ playButton.rec.x + (playButton.rec.width / 12), playButton.rec.y + (playButton.rec.height / 4) }), 54, 0, RAYWHITE);
            DrawTextEx(mainFont, "Quit", Vector2({ quitButton.rec.x + (quitButton.rec.width / 15), quitButton.rec.y + (quitButton.rec.height / 4) }), 54, 0, RAYWHITE);

            EndDrawing();
    }
}
// maika mu she eba 