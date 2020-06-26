#include "../headers/worker.h"

worker::worker()
{
	age = 10; // a warrior is 20;
	food_level = 15;
	food_maximum = 20;
}

worker::~worker()
{
}

int worker::feedWorker(int food_quantity)
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

void worker::printStateLog()
{
	std::cout << " Worker:" << std::endl;
	std::cout << "       current food             : " << food_level << std::endl;
	std::cout << "       current age              : " << age << std::endl;
}

bool worker::maturityAttain()
{
	return age >= ageForWarrior;
}