#include "raylib.h"
#include "pch.h"
#define MaxInput     16

int main()
{
    const int screenWidth = 1720;
    const int screenHeight = 900;
    float roundness = 0.5f;

    InitWindow(screenWidth, screenHeight, "bubble");
    SetTargetFPS(10);
    char name[MaxInput + 1] = "\0";      
    int letterCount = 0;

    Rectangle textBox = { 
        screenWidth / 2.0f - 200, 350, 350, 50
    };
    bool mouseOnText = false;

    int framesCounter = 0;

    while (!WindowShouldClose())
    {
        if (CheckCollisionPointRec(GetMousePosition(), textBox))
        {
            mouseOnText = true;
        }
        else
        {
            mouseOnText = false;
        }

        if (mouseOnText)
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
        }
        else
        {
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        }

        if (mouseOnText)
        {
            framesCounter++;
        }
        else
        {
            framesCounter = 0;
        }

        BeginDrawing();

        ClearBackground(DARKBLUE3);

        DrawText("Hover the imput feild to type",screenWidth / 2 - 100, 220, 20, GRAY);

        DrawRectangleRounded(textBox, roundness, 100, RAYWHITE);

        DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);

        DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MaxInput), screenWidth / 2 - 120, 420, 20, DARKBLUE1);

        if (mouseOnText)
        {
            if (letterCount < MaxInput)
            {
                if (IsKeyPressed(KEY_ENTER))
                {
                    //cipherload
                    DrawText("us be", (int)textBox.x + 160 + MeasureText(name, 40), (int)textBox.y + 200, 40, MAROON);
                    EndDrawing();
                }
            }
            else
            {
                DrawText("Please enter up to 16 characters!", screenWidth / 2 - 120, 520, 20, GRAY);
            }
        }

        EndDrawing();
    }

    CloseWindow();  
}

// Check if any key is pressed
// limit keys check to keys between 32 and 126
bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126)) keyPressed = true;

    return keyPressed;
}