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
		break;
	case TypeSquare::Obstacle:
		rectangle.setFillColor(sf::Color(0, 0, 0));
		break;
	case TypeSquare::Food:
		rectangle.setFillColor(sf::Color(255, 50, 50));
		break;
	case TypeSquare::Anthill:
		rectangle.setFillColor(sf::Color(50, 255, 50));
		break;
	case TypeSquare::Ant:
		rectangle.setFillColor(sf::Color(50, 50, 255));
		break;
	default:
		break;
	}

	position.x = x * 15;
	position.y = y * 15;

	rectangle.setSize(sf::Vector2f(width, height));
	rectangle.setPosition(position);
}

void square::draw(sf::RenderTarget &renderTarget, sf::RenderStates renderStates) const
{
	renderTarget.draw(rectangle);
}

TypeSquare square::getType()
{
	return type;
}

int square::getX()
{
	return x;
}

int square::getY()
{
	return y;
}