#pragma once
#include "raylib.h"

void drawInput(const int screenWidth, int framesCounter, int letterCount, float roundnessTextBox, float roundnessMain);

int Active(int framesCounter, int letterCount);

int nonActive(int framesCounter);

bool IsAnyKeyPressed();