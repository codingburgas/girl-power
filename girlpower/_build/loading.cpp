#include "pch.h"

Rectangle loading =
{
        285,
        372,
        1157,
        156
};

bool LoadingLoop()
{
    float timePlayed = 0;
    float roundness = 0.5f;
    InitAudioDevice();

    Music music = LoadMusicStream("assets/sounds/Loading.ogg");

    PlayMusicStream(music);
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

            if (pause)
            {
                PauseMusicStream(music);
            }
            else
            {
                ResumeMusicStream(music);
            }

            timePlayed = GetMusicTimePlayed(music) / GetMusicTimeLength(music);

            if (timePlayed > 1.0f) timePlayed = 1.0f;

            BeginDrawing();
            float round = 0.1f;
            mainCipherTemplate(round);
            DrawText("LOADING...", 739, 240, 60, LIGHTGRAY);
            DrawRectangleRounded(loading, roundness, 10, RAYWHITE);
            DrawRectangleRounded(Rectangle{ 401, 430, (float)(timePlayed * 850.0f), 50 }, roundness, 50, PURPLE2);

            EndDrawing();

        }
        UnloadMusicStream(music);

        CloseAudioDevice();

        CloseWindow();
    }
    return false;
}