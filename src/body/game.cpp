#include "../headers/game.h"

// initialisation du pointeur de singleton à zéro
// (insérer dans le .cpp)
void game::run()
{
	myField->generateSquares();
	//myField->affichesSquares();
	sf::RenderWindow window(sf::VideoMode(1500, 750), "Ant survival");
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

		myField->move();
		myField->checkLife();
		finGame = myField->checkLivingAnt();

		window.clear();
		myField->drawContainer(window);
		window.display();
		sleep(1);
	}

	std::cout << "end of the game ..." << std::endl;
	window.close();
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
