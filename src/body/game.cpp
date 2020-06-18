#include "../headers/game.h"

// initialisation du pointeur de singleton à zéro
// (insérer dans le .cpp)
game *game::singleton = nullptr;
void game::run()
{
	finGame = false;
	while (!finGame)
	{
		myField->move();
		myField->checkLife();
		myField->
	}
}

void game::display()
{
	myField->affichesSquares();
	sf::RenderWindow window(sf::VideoMode(1500, 750), "Ant survival");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				finGame = true;
				window.close();
			}
		}

		window.clear();
		myField->drawContainer(window);
		window.display();
	}
}
game::game()
{
	myField.generateSquares();
	//TODO init all the component
}
