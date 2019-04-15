#pragma once
#include "Snake.h"
#include "Simple_apple.h"
#include <Windows.h>
#include <SFML/Graphics.hpp>
class Game
{
public:
	Snake player;
	std::vector <Simple_apple> apples;
	sf::RenderWindow window;
	bool run;
	virtual bool Iteration(int turn, sf::RenderWindow* window) = 0;
	virtual bool Execute() = 0;
	virtual void Finish(bool Collided);
	Game();
	~Game();
};

