#pragma once
#include "Game.h"
#include "Border.h"
#include <cstdlib>
class Game_bordered : public Game
{
public:
	Border border;
	Game_bordered();
	Game_bordered(const Game_bordered &);
	~Game_bordered();
	bool Iteration(int turn, sf::RenderWindow* win) override;
	bool Execute() override;
	virtual bool Collided();
};
