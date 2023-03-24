#include "loading.h"
#include "main.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "loading page");

    InitAudioDevice();

    Music music = LoadMusicStream("assets\sounds\Loading.mp3");

    PlayMusicStream(music);

    float timePlayed = 0.0f;        
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

        ClearBackground(LIGHTBLACK);

        DrawText("MUSIC SHOULD BE PLAYING!", 255, 150, 20, LIGHTGRAY);

        DrawRectangle(200, 200, 400, 12, LIGHTGRAY);
        DrawRectangle(200, 200, (int)(timePlayed * 400.0f), 12, MAROON);
        DrawRectangleLines(200, 200, 400, 12, GRAY);

        DrawText("PRESS SPACE TO RESTART MUSIC", 215, 250, 20, LIGHTGRAY);
        DrawText("PRESS P TO PAUSE/RESUME MUSIC", 208, 280, 20, LIGHTGRAY);

        EndDrawing();
    }

    UnloadMusicStream(music);   

    CloseAudioDevice();    

    CloseWindow();

    return 0;
}