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


    InitWindow(screenWidth, screenHeight, "cipher");
    MainMenuLoop(screenWidth, framesCounter, letterCounter, roundnessMain, roundnessTextBox, mouseOnText);
    //input box window 
    
    SetTargetFPS(10);

}