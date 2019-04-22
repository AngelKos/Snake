#include "Button.h"
#include <sstream>



Button::Button(int x, int y, int size_x, int size_y, std::string text)
{
	X = x;
	Y = y;
	Size_X = size_x;
	Size_Y = size_y;
	this->Text = text;
}


Button::~Button()
{
}

bool Button::Click(int x, int y)
{
	return (x >= X && x <= X + Size_X && y >= Y && y <= Y + Size_Y);
}

void Button::Draw(sf::RenderWindow * window)
{
	sf::RectangleShape square = sf::RectangleShape(sf::Vector2f(this->Size_X, this->Size_Y));
	square.setFillColor(sf::Color::Blue);
	square.setPosition(sf::Vector2f(this->X, this->Y));
	window->draw(square);
	sf::Font font;
	font.loadFromFile("C:\\Users\\User\\Documents\\Informatics\\Snake\\a_Futurica.ttf");
	sf::Text text("", font, 20);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(X + 100, Y + 15);
	text.setString(Text);
	window->draw(text);
}
