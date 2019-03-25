#include "Game.h"


Game::Game()
{
	run = true;
};

Game::~Game() {};

void Game::Finish()
{
	run = false;
};
