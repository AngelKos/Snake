#include "Button.h"



Button::Button(int x, int y, int size_x, int size_y)
{
	X = x;
	Y = y;
	Size_X = size_x;
	Size_Y = size_y;
}


Button::~Button()
{
}

bool Button::Click(int x, int y)
{
	return (x >= X && x <= X + Size_X && y >= Y && y <= Y + Size_Y);
}
