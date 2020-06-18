#include "../headers/game.h"

// initialisation du pointeur de singleton à zéro
// (insérer dans le .cpp)
void game::run()
{
	myField->generateSquares();
	myField->affichesSquares();
	sf::RenderWindow window(sf::VideoMode(1500, 750), "Ant survival");
	int counter = 0;
	while (window.isOpen() && !finGame)
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

		myField->checkLife();

		//myField->

		if (counter < 10)
		{
			myField->move();
		}
		counter++;

		window.clear();
		myField->drawContainer(window);
		window.display();
	}
}
game::game()
{
	myField = new field();
	finGame = false;
	//TODO init all the component
}

game::~game()
{
	delete myField;
}
