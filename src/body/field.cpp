#include "../headers/field.h"

field::field()
{
	anthill *acrobat = new anthill();
	anthills.push_back(acrobat);
}

field::field(std::string nameFile)
{
}

field::~field()
{
	for (square *e : squares)
	{
		delete e;
	};
	for (anthill *e : anthills)
	{
		delete e;
	};
}

std::array<std::array<char, width>, height> field::generateRandomMap()
{
	std::srand(std::time(nullptr));
	std::array<std::array<char, width>, height> b;
	int rand, numO = 0, numF = 0;
	for (int i = 0; i < height; i++)
	{
		for (int u = 0; u < width; u++)
		{
			rand = std::rand() % 10;

			if (i == height / 2 && u == width / 2)
			{
				b[i][u] = 'H';
			}
			else if (rand == 0) //food=1/10
			{
				numF++;
				b[i][u] = 'F';
			}
			else if (rand == 1 || rand == 2) //obstacle=2/10
			{
				numO++;
				b[i][u] = 'O';
			}
			else
			{
				b[i][u] = 'E';
			}
		}
	}
	return b;
}

void field::generateSquares()
{
	std::array<std::array<char, width>, height> defaultMap = generateRandomMap();
	for (int i = 0; i < height; i++)
	{
		for (int u = 0; u < width; u++)
		{
			switch (defaultMap[i][u])
			{
			case 'E':
				squares.push_back(new square(i, u, TypeSquare::Empty));
				break;
			case 'O':
				squares.push_back(new square(i, u, TypeSquare::Obstacle));
				break;
			case 'F':
				squares.push_back(new square(i, u, TypeSquare::Food));
				break;
			case 'A':
				squares.push_back(new square(i, u, TypeSquare::Ant));
				break;
			case 'H':
				squares.push_back(new square(i, u, TypeSquare::Anthill));
				break;

			default:
				break;
			}
		}
	}
}

std::vector<square *> field::getSquares()
{
	return squares;
}

void field::affichesSquares()
{
	for (int i = 0; i < height; i++)
	{
		std::cout << "| ";
		for (int u = 0; u < width; u++)
		{
			switch (squares[(i * width) + u]->getType())
			{
			case TypeSquare::Empty:
				std::cout << "_";
				break;
			case TypeSquare::Obstacle:
				std::cout << "O";
				break;
			case TypeSquare::Food:
				std::cout << "F";
				break;
			case TypeSquare::Anthill:
				std::cout << "H";
				break;
			case TypeSquare::Ant:
				std::cout << "A";
				break;
			default:
				break;
			}
		}
		std::cout << " |" << std::endl;
	}
}

void field::afficheDefaut()
{
	generateSquares();

	for (int i = 0; i < height; i++)
	{
		std::cout << "| ";
		for (int u = 0; u < width; u++)
		{
			switch (squares[(i * width) + u]->getType())
			{
			case TypeSquare::Empty:
				std::cout << "_";
				break;
			case TypeSquare::Obstacle:
				std::cout << "O";
				break;
			case TypeSquare::Food:
				std::cout << "F";
				break;
			case TypeSquare::Anthill:
				std::cout << "H";
				break;
			case TypeSquare::Ant:
				std::cout << "A";
				break;
			default:
				break;
			}
		}
		std::cout << " |" << std::endl;
	}
}

void field::drawContainer(sf::RenderWindow &window)
{
	for (std::size_t i = 0; i < squares.size(); ++i)
	{
		window.draw(*squares[i]);
	}
}

void field::move()
{
	int xwarrior;
	int ywarrior;
	int caseWarrior;
	int mybestCase;
	bool fullFood;
	for (anthill *e : anthills)
	{
		for (int i = 0; i < e->getWarriors().size(); i++)
		{
			fullFood = e->getWarriors()[i]->getfood_state();
			xwarrior = e->getWarriors()[i]->getX();
			ywarrior = e->getWarriors()[i]->getY();
			caseWarrior = xwarrior * width + ywarrior;
			//check des alentours
			mybestCase = bestCase(caseWarrior, fullFood);
			std::cout << mybestCase << std::endl;
			e->getWarriors()[i]->move(xwarrior + 1, ywarrior);
			std::cout << e->getWarriors()[i]->getX() << " " << e->getWarriors()[i]->getY() << std::endl;
			std::cout << "case du warrior est la num: " << caseWarrior << std::endl;
		}
	}
}

int field::bestCase(int caseWarrior, bool fullFood)
{
	int best, EmptyCase = 0, FoodCase = 0;
	int caseCheck[8];
	caseCheck[0] = caseWarrior - 1;
	caseCheck[1] = caseWarrior + 1;
	caseCheck[2] = caseWarrior - 50;
	caseCheck[3] = caseWarrior + 50;
	caseCheck[4] = caseWarrior - 51;
	caseCheck[5] = caseWarrior - 49;
	caseCheck[6] = caseWarrior + 51;
	caseCheck[7] = caseWarrior + 49;
	for (int i = 0; i < 8; i++)
	{
		switch (squares[caseCheck[i]]->getType())
		{
		case TypeSquare::Empty:
			EmptyCase = caseCheck[i];
			break;
		case TypeSquare::Food:
			FoodCase = caseCheck[i];
			break;
		default:
			break;
		}
	}
	if (FoodCase != 0)
	{
		best = FoodCase;
	}
	else
	{
		best = EmptyCase;
	}
	return best;
}