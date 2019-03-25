#include "Game_borderless.h"
#include <sstream>

Game_borderless::Game_borderless() : Game() {}

Game_borderless::Game_borderless(const Game_borderless &) : Game() {}

Game_borderless::~Game_borderless() {}

bool Game_borderless::Iteration(int turn, sf::RenderWindow* win)
{
	if (apples.size() < 10)
	{
		apples.push_back(Simple_apple(5, (rand() % 79) * 10, (rand() % 59) * 10, 5, win));
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
	return player.Move(turn);
}

bool Game_borderless::Execute()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
	player = Snake(800 / 2, 600 / 2, &window);
	std::srand((unsigned int)time(0));
	double sleep = 100;
	while (run && window.isOpen())
	{
		sleep = (100 - (player.length - 10) > 0)? 100 - (player.length - 10) : 10;
		Sleep(sleep);// ������� ������� ���� ����������
		sf::Event event;
		int turn = 0;
		// ������� ���������� ������� (����� ��� ������� ��������)
		sf::Clock clock;
		float time;
		// �������� ������������ ������������� (��� ������� ��������)
		window.setVerticalSyncEnabled(true);

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed ||
				(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Up: turn = 1; break;
				case sf::Keyboard::Right: turn = 2; break;
				case sf::Keyboard::Down: turn = 3; break;
				case sf::Keyboard::Left: turn = 4; break;
				}
			}
		}
		window.clear();
		time = clock.getElapsedTime().asMilliseconds();
		clock.restart();
		// ��� ����� ���������� ������� ���������� � ��������� ��������
		if (Iteration(turn, &window))
		{
			player.Draw();
		}
		else
		{
			run = false;
		}
		for (int i = 0; i < 800; i+=10)
		{
			sf::RectangleShape square = sf::RectangleShape(sf::Vector2f(10, 10));
			square.setFillColor(sf::Color::Red);
			square.setPosition(sf::Vector2f(i, 0));
			window.draw(square);
			square.setPosition(sf::Vector2f(i, 590));
			window.draw(square);
			if (i < 600)
			{
				square.setPosition(sf::Vector2f(0, i));
				window.draw(square); 
				square.setPosition(sf::Vector2f(790, i));
				window.draw(square);
			}
		}
		sf::Font font;
		font.loadFromFile("C:\\Users\\User\\Documents\\Informatics\\Snake\\a_Futurica.ttf");
		sf::Text text("" , font, 20);
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);
		text.setPosition(350, 30);
		std::ostringstream playerScore;
		playerScore << player.length - 10;
		text.setString("Scores:" + playerScore.str());
		window.draw(text);
		// ���������
		window.display();
	}
	return 0;
}
