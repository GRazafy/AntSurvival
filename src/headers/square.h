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
	TypeSquare getType();
	void changeAntInIt(square *a);

private:
	bool antInIt;
	TypeSquare type;
	int x;
	int y;
	virtual void draw(sf::RenderTarget &renderTarget, sf::RenderStates renderStates) const;

	sf::RectangleShape rectangle;
	sf::Vector2f position;
	float width;
	float height;
	sf::Color colour;
};

#endif // SQUARE_H_*/