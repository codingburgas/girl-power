#include "pch.h"
using namespace std;

Rectangle layout =
{
	35,
	25,
	1650,
	850
};

void mainCipherTemplate(float roundness)
{
	ClearBackground(DARKBLUE3);

	DrawRectangleRounded(layout, roundness, 10, DARKBLUE1);
}
