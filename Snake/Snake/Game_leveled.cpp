#include "Game_leveled.h"



Game_leveled::Game_leveled()
{
	level = 0;
	Levels.push_back({ Block(std::make_pair(250, 100), std::make_pair(300, 20)), Block(std::make_pair(250, 500), std::make_pair(300, 20)), Block(std::make_pair(100, 200), std::make_pair(20, 200)), Block(std::make_pair(700, 200), std::make_pair(20, 200)) });
	Levels.push_back({ Block(std::make_pair(30, 20), std::make_pair(20, 560)), Block(std::make_pair(750, 20), std::make_pair(20, 560)) });
}


Game_leveled::~Game_leveled()
{
}

bool Game_leveled::Collided()
{
	bool coll = false;
	for (int i = 0; i < Levels[level].size(); i++)
	{
		Levels[level][i].Draw(&window);
		if (Levels[level][i].Collided(player.coord_start.first, player.coord_start.second)) coll = true;
	}
	return (coll || border.Collided(player.coord_start.first, player.coord_start.second));
}

void Game_leveled::Finish(bool Collided)
{
	if (Collided) run = false;
	else
	{
		level++;
		player.coord_start.first = 800 / 2;
		player.coord_start.second = 600 / 2;
		player.coord_finish.first = 800 / 2 - 10 * 10;
		player.coord_finish.second = 600 / 2;
		player.speed.first = 10;
		player.speed.second = 0;
		player.length = 10;
		player.direction = 2;
		player.stable_points.clear();
		if (Levels.size() <= level) run = false;
	}
}

bool Game_leveled::Iteration(int turn, sf::RenderWindow* win)
{
	for (int i = 0; i < Levels[level].size(); i++)
	{
		Levels[level][i].Draw(win);
	}
	if (apples.size() < 10)
	{
		int x = (rand() % 79) * 10;
		int y = (rand() % 59) * 10;
		bool coll = false;
		for (int i = 0; i < Levels[level].size(); i++)
		{
			if (Levels[level][i].Collided(x, y)) coll = true;
		}
		while (coll)
		{
			int x = (rand() % 79) * 10;
			int y = (rand() % 59) * 10;
			coll = false;
			for (int i = 0; i < Levels[level].size(); i++)
			{
				if (Levels[level][i].Collided(x, y)) coll = true;
			}
		}
		apples.push_back(Simple_apple(5, x, y, 5, win));
	}
	for (int i = 0; i < apples.size(); i++)
	{
		if (apples[i].Eaten(player.coord_start.first, player.coord_start.second))
		{
			player.Eats(apples[i].Score);
			apples.erase(apples.begin() + i, apples.begin() + i + 1);
		}
		else apples[i].Draw();
	}
	return (player.Move(turn) && !Collided());
}