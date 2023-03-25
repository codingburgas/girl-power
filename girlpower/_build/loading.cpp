#include "loading.h"
#include "pch.h"

bool audioLoading(const int screenWidth, const int screenHeight)
{
    InitAudioDevice();

    Music music = LoadMusicStream("assets\sounds\Loading.ogg");

    PlayMusicStream(music);

    float timePlayed = 0.0f;        
    bool pause = false;             

    while (!WindowShouldClose())    
    {
        UpdateMusicStream(music);

        if (IsKeyPressed(KEY_SPACE))
        {
            StopMusicStream(music);
            PlayMusicStream(music);
        }

        else if (IsKeyPressed(KEY_P))
        {
            pause = !pause;

            if (pause)
            {
                PauseMusicStream(music);
            }
            else
            {
                ResumeMusicStream(music);
            }
        }

        timePlayed = GetMusicTimePlayed(music) / GetMusicTimeLength(music);

        if (timePlayed > 1.0f)
        {
            timePlayed = 1.0f;
        }

        BeginDrawing();

        ClearBackground(DARKBLUE1);

        DrawText("Loading...", 255, 150, 20, RAYWHITE);

        DrawRectangle(200, 200, 400, 12, LIGHTGRAY);
        DrawRectangle(200, 200, (int)(timePlayed * 400.0f), 12, PURPLE2);
        DrawRectangleLines(200, 200, 400, 12, PURPLE1);

        DrawText("PRESS SPACE TO RESTART MUSIC", 215, 250, 20, LIGHTGRAY);
        DrawText("PRESS P TO PAUSE/RESUME MUSIC", 208, 280, 20, LIGHTGRAY);

        EndDrawing();
    }

    UnloadMusicStream(music);   

    return false;
}