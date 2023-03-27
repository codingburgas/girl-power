#include "pch.h"
using namespace std;

bool mainMenuLoop(const int screenWidth, int framesCounter, float roundnessTextBox, float roundnessMain, int letterCounter, bool mouseOnText)
{
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