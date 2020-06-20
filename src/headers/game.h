#ifndef GAME_H_ /* Include guard */
#define GAME_H_

#include "../headers/field.h"
#include <unistd.h>
#include <SFML/Graphics.hpp>

class game
{
private:
	field *myField;
	bool finGame;

public:
	game();
	~game();

	void run();
	void display();
};

#endif // GAME_H_