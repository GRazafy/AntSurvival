#include "../headers/worker.h"

worker::worker()
{
}

worker::~worker()
{
}

int worker::feedWorker(int food_quantity)
{
	if (food_quantity > (food_maximum - food_level))
	{
		food_level = food_maximum;
		return food_maximum - food_level;
	}
	else
	{
		food_level += food_quantity;
		return 0;
	}
}