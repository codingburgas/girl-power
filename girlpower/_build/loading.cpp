#include "raylib.h"
#include "pch.h"
#include "loading.h"

Rectangle loading =
{
        180,
        180,
        440,
        50
};
int main()
{
    const int screenWidth = 1720;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "bubble");

    InitAudioDevice();            

    Music music = LoadMusicStream("assets/sounds/Loading.ogg");

    PlayMusicStream(music);

    float timePlayed = 0.0f;
    float roundness = 0.5f;
    bool pause = false;             

    SetTargetFPS(30);         

    while (!WindowShouldClose())    
    {
        UpdateMusicStream(music);   

        if (IsKeyPressed(KEY_SPACE))
        {
            StopMusicStream(music);
            PlayMusicStream(music);
        }

        if (IsKeyPressed(KEY_P))
        {
            pause = !pause;

            if (pause) PauseMusicStream(music);
            else ResumeMusicStream(music);
        }

        timePlayed = GetMusicTimePlayed(music) / GetMusicTimeLength(music);

        if (timePlayed > 1.0f) timePlayed = 1.0f;   

        BeginDrawing();

        ClearBackground(DARKBLUE3);

        DrawText("MUSIC SHOULD BE PLAYIN", 255, 150, 20, LIGHTGRAY);

        DrawRectangleRounded(loading, roundness, 10, RAYWHITE);
        DrawRectangleRounded(Rectangle{ 200, 200, (float)(timePlayed * 400.0f), 12 }, roundness, 10, PURPLE2);

        DrawText("space - restart audio", 215, 250, 20, LIGHTGRAY);
        DrawText("p - pause", 208, 280, 20, LIGHTGRAY);

        EndDrawing();
        
    }
    UnloadMusicStream(music);   

    CloseAudioDevice();        

    CloseWindow();         
}