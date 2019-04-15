#include "Border.h"



Border::Border(int size_win_x, int size_win_y)
{
	sides[0] = Block(std::pair<int, int>(0, 0), std::pair<int, int>(10, size_win_y));
	sides[1] = Block(std::pair<int, int>(0, 0), std::pair<int, int> (size_win_x, 10));
	sides[2] = Block(std::pair<int, int>(size_win_x - 10, 0), std::pair<int, int>(10, size_win_y));
	sides[3] = Block(std::pair<int, int>(0, size_win_y - 10), std::pair<int, int>(size_win_x, 10));
}


Border::~Border()
{
}

bool Border::Collided(int x, int y)
{
	return (sides[0].Collided(x, y) || sides[1].Collided(x, y) || sides[2].Collided(x, y) || sides[3].Collided(x, y));
}

void Border::Draw(sf::RenderWindow* window)
{
	sides[0].Draw(window);
	sides[1].Draw(window);
	sides[2].Draw(window);
	sides[3].Draw(window);
}