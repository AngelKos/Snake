#pragma once
#include "Apple.h"

class Simple_apple :
	public Apple
{
public:
	sf::RenderWindow* window;

	Simple_apple(int score, int x, int y, int radius, sf::RenderWindow* window);
	bool Draw() override;
	~Simple_apple();
};