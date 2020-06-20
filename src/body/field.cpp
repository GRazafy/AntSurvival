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
			e->getWarriors()[i]->move(squares[mybestCase]->getX(), squares[mybestCase]->getY());

			switch (squares[caseWarrior]->getType())
			{
			case TypeSquare::Empty:
				squares[caseWarrior]->setRectangle(sf::Color(255, 255, 255));
				break;
			case TypeSquare::Obstacle:
				squares[caseWarrior]->setRectangle(sf::Color(0, 0, 0));
				break;
			case TypeSquare::Food:
				squares[caseWarrior]->setRectangle(sf::Color(255, 255, 255));
				squares[caseWarrior]->setType(TypeSquare::Empty);
				break;
			case TypeSquare::Anthill:
				squares[caseWarrior]->setRectangle(sf::Color(50, 255, 50));
				break;
			default:
				break;
			}

			squares[mybestCase]->changeAntInIt(squares[caseWarrior]);
		}
	}
}

void field::checkLife()
{
	for (anthill *e : anthills)
	{
		e->checkLife();
	}
}
int field::bestCase(int caseWarrior, bool fullFood)
{
	int best, counter = 0, emptyTab[8] = {0}, FoodCase = 0;
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
		if (caseWarrior % 50 == 0 && caseCheck[i] % 49 == 0)
		{
			break;
		}
		else if (caseWarrior % 49 == 0 && caseCheck[i] % 50 == 0)
		{
			break;
		}
		else if (caseWarrior < 50 && caseCheck[i] < 0)
		{
			break;
		}
		else if (caseWarrior > 4949 && caseCheck[i] > 4999)
		{
			break;
		}
		switch (squares[caseCheck[i]]->getType())
		{
		case TypeSquare::Empty:
			emptyTab[counter] = caseCheck[i];
			counter++;
			break;
		case TypeSquare::Food:
			FoodCase = caseCheck[i];
			break;
		default:
			break;
		}
	}
	if (fullFood == false)
	{
		if (FoodCase != 0)
		{
			best = FoodCase;
		}
		else if (emptyTab[0] != 0)
		{
			best = emptyTab[std::rand() % counter];
		}
		else
		{
			best = caseWarrior;
		}
	}
	else
	{
		//Algo pour rentrer
	}
	return best;
}