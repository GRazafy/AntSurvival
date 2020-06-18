<<<<<<< HEAD
#include "headers/game.h"

int main()
{
	game *myGame = game::get();
	myGame->run();
	delete myGame;
=======
#include "headers/field.h"
#include <SFML/Graphics.hpp>

std::vector<sf::RectangleShape *> run()
{
}

int main()
{
	field *e = new field();
	e->generateSquares();
	/*e.affichesSquares();
	sf::RenderWindow window(sf::VideoMode(1500, 750), "Ant survival");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		e.drawContainer(window);
		window.display();*/

	/* while (true)
		 {
			 ajout +1 maturité fourmis mort si besoin
			Check cases alentours par FOURMIS, déplacement pour éviter collision, changement d'état de la case (fourmis dessus, bouffe disparait,
			apparition de phéromone) et variables de fourmis, reine et fourmillière (nourriture)



		}
	}*/
	delete e;
	return 0;
>>>>>>> c2f22e219524dbb23730ae4e33ef55e348b216cf
}