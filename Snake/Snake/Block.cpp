#include "Block.h"

Block::Block()
{
	coord_left_up.first = 0;
	coord_left_up.second = 0;
	size.first = 0;
	size.second = 0;
}

Block::Block(std::pair<int, int> Coord, std::pair<int, int> Size)
{
	coord_left_up = Coord;
	size = Size;
}


Block::~Block()
{
}

bool Block::Collided(int x, int y)
{
	return (x > coord_left_up.first && x < coord_left_up.first + size.first && y > coord_left_up.second && y < coord_left_up.second + size.second);
}

void Block::Draw(sf::RenderWindow* window)
{
	sf::RectangleShape square = sf::RectangleShape(sf::Vector2f(size.first, size.second));
	square.setFillColor(sf::Color::Red);
	square.setPosition(sf::Vector2f((float)coord_left_up.first, (float)coord_left_up.second));
	window->draw(square);
}