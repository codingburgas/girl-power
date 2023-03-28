#include "pch.h"
using namespace std;

Rectangle layout =
{
	35,
	25,
	1650,
	850
};
Rectangle TopLeft =
{
	261,
	213,
	567,
	266
};
Rectangle TopRight =
{
	915,
	213,
	567,
	266
};
Rectangle BottomLeft =
{
	261,
	552,
	567,
	266
};
Rectangle BottomRight =
{
	915,
	552,
	567,
	266
};
void MainCipherTemplate(float roundness)
{
	ClearBackground(DARKBLUE3);

	DrawRectangleRounded(layout, roundness, 10, DARKBLUE1);
}
void MenuCipherTemplate(float roundness)
{
	ClearBackground(DARKBLUE3);
	DrawRectangleRounded(TopLeft, roundness, 10, DARKBLUE1);
	DrawRectangleRounded(TopRight, roundness, 10, DARKBLUE1);
	DrawRectangleRounded(BottomLeft, roundness, 10, DARKBLUE1);
	DrawRectangleRounded(BottomRight, roundness, 10, DARKBLUE1);
}
