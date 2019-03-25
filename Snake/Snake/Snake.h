#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
class Snake
{
private:
	bool Collision()
	{
		bool b = false;
		int x, y;
		x = coord_start.first, y = coord_start.second;
		int t = stable_points.size() - 1;
		for (int i = 1; i <= length; i++)
		{
			if (t >= 0)
			{
				if (x == stable_points[t].first)
				{
					if (y >= stable_points[t].second)
					{
						while (y != stable_points[t].second)
						{
							y -= 10;
							i++;
							if (coord_start.first == x && coord_start.second == y) b = true;
						}
					}
					else
						while (y != stable_points[t].second)
						{
							y += 10;
							i++;
							if (coord_start.first == x && coord_start.second == y) b = true;
						}
					t--;
					i--;
				}
				else if (y == stable_points[t].second)
				{
					if (x >= stable_points[t].first)
					{
						while (x != stable_points[t].first)
						{
							x -= 10;
							i++;
							if (coord_start.first == x && coord_start.second == y) b = true;
						}
					}
					else
						while (x != stable_points[t].first)
						{
							x += 10;
							i++;
							if (coord_start.first == x && coord_start.second == y) b = true;
						}
					t--;
					i--;
				}
			}
			else
			{
				if (x == coord_finish.first)
				{
					if (y >= coord_finish.second)
					{
						while (y != coord_finish.second)
						{
							y -= 10;
							i++;
							if (coord_start.first == x && coord_start.second == y) b = true;
						}
					}
					else
						while (y != coord_finish.second)
						{
							y += 10;
							i++;
							if (coord_start.first == x && coord_start.second == y) b = true;
						}
					t--;
					i--;
				}
				else if (y == coord_finish.second)
				{
					if (x >= coord_finish.first)
					{
						while (x != coord_finish.first)
						{
							x -= 10;
							i++;
							if (coord_start.first == x && coord_start.second == y) b = true;
						}
					}
					else
						while (x != coord_finish.first)
						{
							x += 10;
							i++;
							if (coord_start.first == x && coord_start.second == y) b = true;
						}
					t--;
					i--;
				}
			}
			if (coord_start.first == x && coord_start.second == y) b = true;
		}
		if (coord_start.first < 10 || coord_start.first > 790 || coord_start.second < 10 || coord_start.second > 590) b = true;
		return b;
	}
	int direction;
public:
	std::pair<int, int> coord_start;
	std::pair<int, int> coord_finish;
	std::pair<int, int> speed;
	std::vector<std::pair<int, int>> stable_points;
	sf::RenderWindow* window; // ”казатель на окно, нужен дл€ отрисовки
	int length;
	int Turn;
	Snake() {}
	Snake(int x, int y, sf::RenderWindow* window)
	{
		coord_start.first = x;
		coord_start.second = y;
		coord_finish.first = x - 10 * 10;
		coord_finish.second = y;
		speed.first = 10;
		speed.second = 0;
		length = 10;
		direction = 2;
		this->window = window;
	};
	~Snake() {}
	bool Move(int turn)
	{
		if (turn == 0) turn = direction;
		else if ((turn + direction) % 2 == 1)
		{
			if (turn != direction) stable_points.push_back(coord_start);
			direction = turn;
		}
		else
		{
			turn = direction;
		}
		switch (turn)
		{
		case 1: { speed = { 0, -10 }; break; }
		case 2: { speed = { 10, 0 }; break; }
		case 3: { speed = { 0, 10 }; break; }
		case 4: { speed = { -10, 0 }; break; }
		case 0: turn = direction; break;
		}
		coord_start = { coord_start.first + speed.first, coord_start.second + speed.second };
		if (stable_points.size() > 0)
		{
			if (coord_finish.first == stable_points[0].first)
			{
				if (coord_finish.second > stable_points[0].second) coord_finish.second -= 10;
				else coord_finish.second += 10;
			}
			else if (coord_finish.second == stable_points[0].second)
			{
				if (coord_finish.first > stable_points[0].first) coord_finish.first -= 10;
				else coord_finish.first += 10;
			}
			if (coord_finish == stable_points[0]) stable_points.erase(stable_points.begin(), stable_points.begin() + 1);
		}
		else
		{
			coord_finish = { coord_finish.first + speed.first, coord_finish.second + speed.second };
		}
		return !Collision();
	}
	void Draw()
	{
		int x, y;
		x = coord_start.first, y = coord_start.second;
		int t = stable_points.size() - 1;
		for (int i = 1; i <= length; i++)
		{
			sf::RectangleShape square = sf::RectangleShape(sf::Vector2f(10, 10));
			square.setPosition((float)x, (float)y);
			square.setFillColor(sf::Color::Green);
			window->draw(square);
			if (t >= 0)
			{
				if (x == stable_points[t].first)
				{
					if (y >= stable_points[t].second)
					{
						while (y != stable_points[t].second)
						{
							y-=10;
							i++;
							square.setPosition((float)x, (float)y);
							window->draw(square);
						}
					}
					else
						while (y != stable_points[t].second)
						{
							y+=10;
							i++;
							square.setPosition((float)x, (float)y);
							window->draw(square);
						}
					t--;
					i--;
				}
				else if (y == stable_points[t].second)
				{
					if (x >= stable_points[t].first)
					{
						while (x != stable_points[t].first)
						{
							x-=10;
							i++; 
							square.setPosition((float)x, (float)y);
							window->draw(square);
						}
					}
					else
						while (x != stable_points[t].first)
						{
							x+=10;
							i++;
							square.setPosition((float)x, (float)y);
							window->draw(square);
						}
					t--;
					i--;
				}
			}
			else
			{
				if (x == coord_finish.first)
				{
					if (y >= coord_finish.second)
					{
						while (y != coord_finish.second)
						{
							y -= 10;
							i++;
							square.setPosition((float)x, (float)y);
							window->draw(square);
						}
					}
					else
						while (y != coord_finish.second)
						{
							y += 10;
							i++;
							square.setPosition((float)x, (float)y);
							window->draw(square);
						}
					t--;
					i--;
				}
				else if (y == coord_finish.second)
				{
					if (x >= coord_finish.first)
					{
						while (x != coord_finish.first)
						{
							x -= 10;
							i++;
							square.setPosition((float)x, (float)y);
							window->draw(square);
						}
					}
					else
						while (x != coord_finish.first)
						{
							x += 10;
							i++;
							square.setPosition((float)x, (float)y);
							window->draw(square);
						}
					t--;
					i--;
				}
			}
		}
	}
	void Eats(int Score)
	{
		if (coord_finish.first == stable_points[0].first)
		{
			if (coord_finish.second > stable_points[0].second) coord_finish.second += Score * 10;
			else coord_finish.second -= Score * 10;
		}
		else
		{
			if (coord_finish.first > stable_points[0].first) coord_finish.first += Score * 10;
			else coord_finish.first -= Score * 10;
		}
		length += Score;
	}
};
