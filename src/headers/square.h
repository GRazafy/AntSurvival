#ifndef SQUARE_H_ /* Include guard */
#define SQUARE_H_
#include <SFML/Graphics.hpp>
#include <iostream>
enum TypeSquare
{
	Obstacle,
	Empty,
	Food,
	Anthill
};

class square : public sf::Drawable
{
public:
	square();
	square(int x, int y, TypeSquare type);
	~square();

	int getX();
	int getY();
	int getFood();

	TypeSquare getType();
	void setType(TypeSquare new_type);
	void setRectangle(sf::Color colour);

	void changeAntInIt();
	int takeFood(int current_level, int capacity);
	int feedAnt(int current_food, int food_max);

private:
	bool antInIt;
	TypeSquare type;
	int x;
	int y;
	virtual void draw(sf::RenderTarget &renderTarget, sf::RenderStates renderStates) const;
	int foodInSquare;

	sf::RectangleShape rectangle;
	sf::Vector2f position;
	float width;
	float height;
	sf::Color colour;
};

#endif // SQUARE_H_*/