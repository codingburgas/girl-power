#include "pch.h"
#define max 16

Rectangle textBox =
{
    650,
    350,
    450,
    50
};
Rectangle background =
{
    35,
    25,
    1650,
    850
};
bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126)) keyPressed = true;

    return keyPressed;
}
bool inputBox()
{
    const int screenWidth = 1720;
    const int screenHeight = 900;
    float roundness = 0.1f;

    InitWindow(screenWidth, screenHeight, "cipher");

    char name[max + 1] = "\0";      
    int letterCount = 0;

    bool mouseOnText = false;

    int framesCounter = 0;

    SetTargetFPS(10);         
    while (!WindowShouldClose())    
    {
        if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
        else mouseOnText = false;

        if (mouseOnText)
        {
            SetMouseCursor(MOUSE_CURSOR_IBEAM);

            int key = GetCharPressed();

            while (key > 0)
            {
                if ((key >= 32) && (key <= 125) && (letterCount < max))
                {
                    name[letterCount] = (char)key;
                    name[letterCount + 1] = '\0'; 
                    letterCount++;
                }

                key = GetCharPressed();  
            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                name[letterCount] = '\0';
            }
            else if (IsKeyPressed(KEY_ENTER))
            {
                float roundness = 0.5f;
                float timePlayed = 0.0f;
                if (LoadingLoop()) return true;
                else return false;
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (mouseOnText)
        {
            framesCounter++;
        }
        else
        {
            framesCounter = 0;
        }

        BeginDrawing();

        mainCipherTemplate(roundness);

        DrawText("Hover the imput feild to enter your password", screenWidth / 2 - 100, 220, 20, PURPLE2);

        DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);

        DrawText(TextFormat("Input: %i/%i", letterCount, max), 315, 250, 20, DARKGRAY);

        if (mouseOnText)
        {
            if (letterCount < max)
            {
                if (((framesCounter / 20) % 2) == 0) DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40), (int)textBox.y + 12, 40, MAROON);
            }
            else DrawText("Too much characters!", 230, 300, 20, GRAY);
        }

        EndDrawing();
    }

    CloseWindow();

    return false;
}