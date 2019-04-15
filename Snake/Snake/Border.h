#pragma once
#include "Block.h"
class Border
{
public:
	Block sides[4];
	Border()
	{
		sides[0] = Block(std::pair<int, int>(0, 0), std::pair<int, int>(10, 600));
		sides[1] = Block(std::pair<int, int>(0, 0), std::pair<int, int>(800, 10));
		sides[2] = Block(std::pair<int, int>(800 - 10, 0), std::pair<int, int>(10, 600));
		sides[3] = Block(std::pair<int, int>(0, 600 - 10), std::pair<int, int>(800, 10));
	}
	Border(int size_win_x, int size_win_y);
	~Border();
	bool Collided(int x, int y);
	void Draw(sf::RenderWindow* window);
};

