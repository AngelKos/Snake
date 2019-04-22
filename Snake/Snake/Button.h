#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Button
{
public:
	int X;
	int Y;
	int Size_X;
	int Size_Y;
	std::string Text;
	Button(int x, int y, int size_x, int size_y, std::string text);
	~Button();
	bool Click(int x, int y);
	void Draw(sf::RenderWindow * window);
};

