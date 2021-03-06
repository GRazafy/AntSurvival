#include "../headers/queen.h"

queen::queen() : food_for_birth(10), litter(5), current_eggs(0)
{
	max_age = 200;
	age = 30;
	food_level = 100;
	food_maximum = 100;
}

queen::~queen()
{
}

int queen::layEggs()
{
	int remainingRoom = this->remainingRoom();
	if (food_level >= food_for_birth && remainingRoom != 0)
	{

		if (remainingRoom > this->litter)
		{
			std::cout << "The queen is laying " << litter << " eggs" << std::endl;
			food_level -= food_for_birth;
			current_eggs += litter;
			return litter;
		}
		else
		{

			std::cout << "The queen is laying " << remainingRoom << " eggs" << std::endl;
			food_level -= food_for_birth;
			current_eggs += remainingRoom;
			return remainingRoom;
		}
	}
	else
	{
		if (remainingRoom == 0)
		{
			std::cout << "No more place to lay eggs" << std::endl;
		}
		else
		{
			std::cout << "The queen is too hungry to lay eggs ..." << std::endl;
		}
		return 0;
	}
}

int queen::feedQueen(int food_quantity)
{
	if (food_quantity > (food_maximum - food_level))
	{
		int tmp = food_maximum - food_level;
		food_level = food_maximum;
		return food_quantity - tmp;
	}
	else
	{
		food_level += food_quantity;
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
	food_level -= 2;
	age += 1;
}

void queen::printStateLog()
{
	std::cout << " Queen:" << std::endl;
	std::cout << "       current eggs: " << current_eggs << std::endl;
	std::cout << "       current food: " << food_level << std::endl;
	std::cout << "       current age : " << age << std::endl;
}

void queen::decreaseEggs()
{
	current_eggs--;
}