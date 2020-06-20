#include "../headers/warrior.h"

warrior::warrior() : food_capacity(50), food_quantity(0)
{
	food_level = 15;
	food_maximum = 20;
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