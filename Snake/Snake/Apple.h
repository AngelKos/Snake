#pragma once
#include <SFML/Graphics.hpp>
class Apple
{
public:
	int Score;
	int X, Y;
	int Radius;
	Apple(int score, int x, int y, int radius)
	{
		Score = score;
		X = x;
		Y = y;
		Radius = radius;
	}
	virtual bool Draw() = 0;
	bool Eaten(int x, int y)
	{
		return (x >= X && x <= X + Radius && y >= Y && y <= Y + Radius);
	}
	~Apple() {};
};

