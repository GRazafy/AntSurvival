#include "../headers/warrior.h"
int warrior::nextID = 0;
warrior::warrior() : food_capacity(50), food_quantity(0)
{
	food_level = 15;
	food_maximum = 20;
	id = ++nextID;
}

warrior::~warrior()
{
}

void warrior::move(int x, int y)
{
	this->x = x;
	this->y = y;
}
int warrior::getX()
{
	return this->x;
}
int warrior::getY()
{
	return this->y;
}
void warrior::getFood(square *e)
{
	//food_level = e->feedAnt(food_level, food_maximum);
	food_quantity = e->takeFood(food_quantity, food_capacity);
	std::cout << "ant: " << id << " food quantity: " << food_quantity << " from square: " << e << std::endl;

	if (e->getFood() == 0)
	{
		e->setType(TypeSquare::Empty);
	}
}

bool warrior::getfood_state()
{
	if (this->food_capacity == this->food_quantity)
		return true;
	else
		return false;
}

void warrior::addCase(int bestCase)
{
	path.push_back(bestCase);
}
int warrior::lastCase()
{
	return path.back();
}
void warrior::deleteLast()
{
	path.pop_back();
}
int warrior::foodDeposit()
{
	int tmp = food_quantity;
	food_quantity = 0;
	return tmp;
}