#pragma once
#include "Game.h"
#include "Border.h"
#include <cstdlib>
class Game_bordered : public Game
{
public:
	Border border;
	Game_bordered(sf::RenderWindow* window);
	Game_bordered(const Game_bordered &);
	~Game_bordered();
	bool Iteration(int turn) override;
	bool Execute() override;
	virtual bool Collided();
};
