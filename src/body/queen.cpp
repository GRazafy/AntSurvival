#include "../headers/queen.h"

queen::queen() : food_for_birth(10), threshold_egg(10), litter(2), current_eggs(0)
{
	max_age = 400;
	age = 30;
	food_level = 10;
	food_maximum = 50;
}

queen::~queen()
{
}

int queen::layEggs()
{
	if (food_level >= food_for_birth)
	{

		food_level -= food_for_birth;

		if (this->remainingRoom() > this->litter)
		{
			std::cout << "The queen is laying " << litter << " eggs" << std::endl;
			return litter;
		}
		else
		{
			std::cout << "The queen is laying " << this->remainingRoom() << " eggs" << std::endl;
			return this->remainingRoom();
		}
	}
	else
	{
		std::cout << "The queen is too hungry to lay eggs ..." << std::endl;
		return 0;
	}
}

bool queen::thresholdReached()
{
	return current_eggs > threshold_egg;
}

int queen::remainingRoom()
{
	return threshold_egg - current_eggs;
}

int queen::getAge()
{
	return age;
}

void queen::endTurn()
{
	food_level -= 5;
	age += 1;
}