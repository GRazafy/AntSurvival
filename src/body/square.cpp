#include "../headers/square.h"

square::~square()
{
}

square::square() : x(0),
				   y(0)
{
}

square::square(int x, int y, TypeSquare type) : x(x),
												y(y),
												width(15),
												height(15),
												type(type)
{

	switch (type)
	{
	case TypeSquare::Empty:
		rectangle.setFillColor(sf::Color(255, 255, 255));
		foodInSquare = 0;
		break;
	case TypeSquare::Obstacle:
		rectangle.setFillColor(sf::Color(0, 0, 0));
		foodInSquare = 0;
		break;
	case TypeSquare::Food:
		rectangle.setFillColor(sf::Color(255, 50, 50));
		foodInSquare = 200;
		break;
	case TypeSquare::Anthill:
		rectangle.setFillColor(sf::Color(50, 255, 50));
		foodInSquare = 0;
		break;
	default:
		break;
	}

	position.x = x * 15;
	position.y = y * 15;

	antInIt = false;

	rectangle.setSize(sf::Vector2f(width, height));
	rectangle.setPosition(position);
}

void square::changeAntInIt()
{
	antInIt = !antInIt;
	if (antInIt && this->type != TypeSquare::Anthill)
	{
		rectangle.setFillColor(sf::Color(255, 120, 50));
	}
}

void square::draw(sf::RenderTarget &renderTarget, sf::RenderStates renderStates) const
{
	renderTarget.draw(rectangle);
}

int square::getX()
{
	return x;
}

int square::getY()
{
	return y;
}

int square::getFood()
{
	return foodInSquare;
}

void square::setRectangle(sf::Color colour)
{
	rectangle.setFillColor(colour);
}

int square::takeFood(int current_level, int capacity)
{
	if (foodInSquare > capacity)
	{
		foodInSquare -= (capacity - current_level);
		return capacity;
	}
	else
	{
		if (foodInSquare + current_level > capacity)
		{
			foodInSquare = 0;
			return capacity;
		}
		else
		{
			foodInSquare = 0;
			return foodInSquare + current_level;
		}
	}
}

int square::feedAnt(int current_food, int food_max)
{
	if (foodInSquare > food_max)
	{
		foodInSquare -= (food_max - current_food);
		return food_max;
	}
	else
	{
		if (foodInSquare + current_food > food_max)
		{
			foodInSquare = 0;
			return food_max;
		}
		else
		{
			foodInSquare = 0;
			return foodInSquare + current_food;
		}
	}
}

TypeSquare square::getType()
{
	return type;
}

void square::setType(TypeSquare new_type)
{
	type = new_type;
}