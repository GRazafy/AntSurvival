#include "../headers/warrior.h"

int warrior::nextID = 0; //id of the ant

warrior::warrior() : food_capacity(50), food_quantity(0)
{
	age = 20; // a warrior is 20;
	food_level = 15;
	food_maximum = 20;
	id = ++nextID;
	last_food_square = nullptr;
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
	food_level = e->feedAnt(food_level, food_maximum);
	food_quantity = e->takeFood(food_quantity, food_capacity);

	last_food_square = e;

	//std::cout << "ant: " << id << " food quantity: " << food_quantity << " from square: " << e << std::endl;

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
	std::cout << "quantité de nourriture de fourmis: " << food_quantity << std::endl;
	int tmp = food_quantity;
	food_quantity = 0;
	std::cout << "quantité de nourriture de fourmis: " << food_quantity << std::endl;
	return tmp;
}
void warrior::printStateLog()
{
	std::cout << " Warrior with ID:" << id << std::endl;
	std::cout << "       current food_transporting: " << food_quantity << std::endl;
	std::cout << "       current food             : " << food_level << std::endl;
	std::cout << "       current age              : " << age << std::endl;
	std::cout << "       last food square         :" << last_food_square << std::endl;
}