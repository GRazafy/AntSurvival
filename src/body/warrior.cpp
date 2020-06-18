#include "../headers/warrior.h"

warrior::warrior() : food_capacity(5), food_quantity(0)
{
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