#pragma once
#include "Game.h"
#include <cstdlib>
class Game_borderless : Game
{
public:
	Game_borderless();
	Game_borderless(const Game_borderless &);
	~Game_borderless();
	bool Iteration(int turn, sf::RenderWindow* win) override;
	bool Execute() override;
};
