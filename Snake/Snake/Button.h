#pragma once
class Button
{
public:
	int X;
	int Y;
	int Size_X;
	int Size_Y;
	Button(int x, int y, int size_x, int size_y);
	~Button();
	bool Click(int x, int y);
	void Draw();
};

