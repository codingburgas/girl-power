#pragma once
#include "raylib.h"

struct Button
{
	Rectangle rec;
	short state;
	Color color;
	Color hoverColor;
};


void SetButtonState(Button& button);

bool ChangeButtonByState(Button& button, float startWidth, bool editWidth, bool drawLines);

bool HandleButton(Button& button, float startWidth, bool editWidth, bool drawLines);