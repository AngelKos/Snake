#include "Game.h"


Game::Game(sf::RenderWindow* window)
{
	this->window = window;
	run = true;
};

Game::~Game() {};

void Game::Finish(bool Collided)
{
	run = false;
};
