#pragma once
#include<utility>
#include <SFML/Graphics.hpp>
class Block
{
public:
	std::pair<int, int> coord_left_up;
	std::pair<int, int> size;
	Block();
	Block(std::pair<int,int> Coord, std::pair<int, int> Size);
	~Block();
	bool Collided(int x, int y);
	void Draw(sf::RenderWindow* window);
};

