#pragma once
#include "Game_bordered.h"
class Game_leveled : public Game_bordered
{
	std::vector<std::vector<Block>> Levels;
	int level;
public:
	Game_leveled();
	~Game_leveled();
	bool Collided() override;
	void Finish(bool Collided) override;
	bool Iteration(int turn, sf::RenderWindow* win) override;
};

