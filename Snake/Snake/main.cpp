#include "Game_leveled.h"
#include "Button.h"
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
	Button leveled = Button(250, 100, 300, 50, "Level mode");
	leveled.Draw(&window);
	Button bordered = Button(250, 400, 300, 50, "Infinite mod");
	bordered.Draw(&window);
	window.display();
	sf::Event eve;
	bool lev = false, bor = false;
	while (!lev && !bor)
	{
		window.pollEvent(eve);
		if (eve.type == sf::Event::MouseMoved)
		{
			if (leveled.Click(eve.mouseMove.x, eve.mouseMove.y))
			{
				lev = true;
				break;
			}
			if (bordered.Click(eve.mouseMove.x, eve.mouseMove.y))
			{
				bor = true;
				break;
			}
		}
	}
	
	window.clear();
	if (lev)
	{
		Game_leveled game = Game_leveled(&window);
		game.Execute();
	}
	else if (bor)
	{
		Game_bordered game = Game_bordered(&window);
		game.Execute();
	}
	return 0;
}