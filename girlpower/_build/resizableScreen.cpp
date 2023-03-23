#include "resizableScreen.h"

bool Screen(int screenWidth, int screenHeight)
{
    bool screen = true;
    if (IsWindowResized() && !IsWindowFullscreen())
    {
        screenWidth = GetScreenWidth();
        screenHeight = GetScreenHeight();
    }
    if (IsKeyPressed(KEY_ENTER) && (IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT)))
    {
        int display = GetCurrentMonitor();

        if (IsWindowFullscreen())
        {
            SetWindowSize(screenWidth, screenHeight);
        }
        else
        {
            SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
        }
        ToggleFullscreen();
    }
    return screen;
}