#ifndef GAME_H_ /* Include guard */
#define GAME_H_

#include "../headers/field.h"
#include <SFML/Graphics.hpp>

class game
{
private:
	static game *singleton;
	game();
	field *myField;
	bool finGame;

public:
	game(const game &) = delete;
	game &operator=(const game &) = delete;
	static game *get()
	{
		if (!singleton)
			singleton = new game;
		return singleton;
	};

	void run();
	void display();
};

#endif // GAME_H_