#include "Simple_apple.h"

Simple_apple::Simple_apple(int score, int x, int y, int radius, sf::RenderWindow* window) : Apple(score, x, y, radius)
{
	this->window = window;
}

Simple_apple::~Simple_apple() {}

bool Simple_apple::Draw()
{
	sf::CircleShape apple = sf::CircleShape(Radius, 10000);
	apple.setPosition((float)X, (float)Y);
	apple.setFillColor(sf::Color::Red);
	window->draw(apple);
	return 0;
}
