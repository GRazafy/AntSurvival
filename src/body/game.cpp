#include "../headers/game.h"

// initialisation du pointeur de singleton à zéro
// (insérer dans le .cpp)
void game::run()
{

	myField->generateSquares();
	//myField->affichesSquares();
	sf::RenderWindow window(sf::VideoMode(1500, 750), "Ant survival");
	int counter = 0;
	while (window.isOpen() && !finGame)
	{
		counter += 1;
		std::cout << "Tour n° : " << counter << std::endl;
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
		myField->feedAnt();
		myField->layEggs();
		myField->circleOfLife();
		//TODO circle of life (workers to warriors and pre_natal ants)
		//TODO change the field ?
		finGame = myField->checkLife();

		myField->printStateLog();

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
