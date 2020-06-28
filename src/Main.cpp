#include "headers/game.h"
#include "headers/field.h"

int main()
{

	game *myGame = new game();
	myGame->run();
	delete myGame;
	std::cout << "end of program" << std::endl;
	return 0;
}