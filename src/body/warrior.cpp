#include "../headers/warrior.h"

int warrior::nextID = 0; //id of the ant

warrior::warrior() : food_capacity(50), food_quantity(0)
{
	age = 20; // a warrior is 20;
	food_level = 25;
	food_maximum = 40;
	id = ++nextID;
	last_food_square = nullptr;
	path = std::vector<int>();
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
		e->setRectangle(sf::Color(255, 255, 255));
	}
}

bool warrior::getfood_state()
{
	bool test = false;
	if (this->food_capacity == this->food_quantity)
		test = true;
	return test;
}

void warrior::addCase(int bestCase)
{
	path.push_back(bestCase);
}
int warrior::lastCase()
{
	if (path.empty() == true)
		return false;
	else
		return path.back();
}
void warrior::deleteLast()
{
	if (!path.empty())
		path.pop_back();
}
void warrior::deleteAll()
{
	if (!path.empty())
		path.clear();
}
int warrior::feedWarrior()
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
int warrior::foodDeposit()
{
	std::cout << "quantité de nourriture de fourmis: " << food_quantity << std::endl;
	this->food_quantity = feedWarrior();
	int tmp = this->food_quantity;
	this->food_quantity = 0;

	std::cout << "quantité de nourriture de fourmis: " << food_quantity << std::endl
			  << " et donc le fullfood est à : " << getfood_state() << std::endl;
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