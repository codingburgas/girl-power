#include "pch.h"
#define MaxInput 16

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

char name[MaxInput + 1] = "\0";

bool inputPrint(bool mouseOnText)
{
    if (CheckCollisionPointRec(GetMousePosition(), textBox))
    {
        return mouseOnText = true;
    }
    else
    {
        return mouseOnText = false;
    }
    
}

void drawInput(const int screenWidth, int framesCounter, int letterCount, float roundnessTextBox, float roundnessMain)
{
    ClearBackground(PURPLE1);

    DrawRectangleRounded(background, roundnessMain, 30, DARKBLUE1);

    DrawText("Hover the imput feild to enter your password", screenWidth / 2 - 100, 220, 20, PURPLE2);

    DrawRectangleRounded(textBox, roundnessTextBox, 100, RAYWHITE);

    
    if (CheckCollisionPointRec(GetMousePosition(), textBox))
    {
        DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, PURPLE2);

        if(letterCount < MaxInput)
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                float roundness = 0.5f;
                float timePlayed = 0.0f;
                LoadingLoop(timePlayed, roundness);
            }
        }
    }
    else
    {
        DrawText("Please enter up to 16 characters!", screenWidth / 2 - 120, 520, 20, GRAY);
    }
}

int Active(int framesCounter, int letterCount)
{
    SetMouseCursor(MOUSE_CURSOR_IBEAM);

    int key = GetCharPressed();

    while (key > 0)
    {
        if ((key >= 32) && (key <= 125) && (letterCount < MaxInput))
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
    framesCounter++;
    return framesCounter;
}

int nonActive(int framesCounter)
{
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    framesCounter = 0;
    return framesCounter;
}

bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126)) keyPressed = true;

    return keyPressed;
}