#include "headers/game.h"
#include "headers/field.h"

int main()
{
	/*field *myField = new field();
	myField->generateSquares();
	myField->affichesSquares();
	sf::RenderWindow window(sf::VideoMode(1500, 750), "Ant survival");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				//finGame = true;
				window.close();
			}
		}

		window.clear();
		myField->drawContainer(window);
		window.display();
	}*/

	game *myGame = new game();
	myGame->run();
	delete myGame;
}