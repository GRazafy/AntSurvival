#include "../headers/anthill.h"

anthill::anthill(int ahcase)
{
	this->ahCase = ahcase;
	warriors = std::vector<warrior *>();
	workers = std::vector<worker *>();
	this->_queen = new queen();
	warriors.push_back(new warrior());
	warriors.push_back(new warrior());
	warriors.push_back(new warrior());
	warriors.push_back(new warrior());
	warriors.push_back(new warrior());
	warriors.push_back(new warrior());
	warriors.push_back(new warrior());
	workers.push_back(new worker());

	this->food_capacity = 2000;
	this->food_quantity = 1000;
	current_pre_natals = 0;
}

anthill::~anthill()
{
	delete _queen;
	for (ant *e : warriors)
	{
		delete e;
	}

	for (ant *e : workers)
	{
		delete e;
	}
	for (pre_natal *e : pre_natals)
	{
		delete e;
	}
}

void anthill::removeWarrior(warrior *e)
{
	for (std::vector<warrior *>::iterator i = warriors.begin(); i != warriors.end(); ++i)
	{
		if (*i == e)
		{
			warriors.erase(i--);
		}
	}
}

void anthill::removeWorker(worker *e)
{
	for (std::vector<worker *>::iterator i = workers.begin(); i != workers.end(); ++i)
	{
		if (*i == e)
		{
			workers.erase(i--);
		}
	}
}

void anthill::removePreNatal(pre_natal *e)
{
	for (std::vector<pre_natal *>::iterator i = pre_natals.begin(); i != pre_natals.end(); ++i)
	{
		if (*i == e)
		{
			pre_natals.erase(i--);
		}
	}
}

bool anthill::checkLife()
{

	bool queenDead = false;
	for (warrior *e : warriors)
	{
		e->endTurn();
		if (e->endFood() || e->ageMax())
		{
			std::cout << "a Warrior is dead..." << std::endl;
			removeWarrior(e);
			delete e;
		}
	}
	for (worker *e : workers)
	{
		e->endTurn();
		if (e->endFood() || e->ageMax())
		{
			std::cout << "a Worker is dead..." << std::endl;
			removeWorker(e);
			delete e;
		}
	}

	_queen->endTurn();
	if (_queen->endFood() || _queen->ageMax())
	{
		std::cout << "a queen is dead..." << std::endl;
		queenDead = true;
		delete _queen;
	}

	return workers.empty() && warriors.empty() || queenDead; //true = end of the anthills
}

bool anthill::checkLivingAnt()
{
	return warriors.empty() || _queen == nullptr;
}

std::vector<warrior *> anthill::getWarriors()
{
	return warriors;
}

void anthill::refill(warrior *myWarrior)
{
	std::cout << "An ant is giving food to the anthill" << std::endl;
	int quantity = myWarrior->foodDeposit();
	std::cout << "quantité dans la fourmilière " << this->food_quantity << std::endl;
	this->food_quantity += quantity;
	std::cout << "quantité dans la fourmilière " << this->food_quantity << std::endl;
}

void anthill::layEggs()
{
	if (_queen->thresholdReached())
	{
		std::cout << "the queen can't lay eggs" << std::endl;
	}
	else
	{
		int numberToLay = _queen->layEggs();
		int counter = current_pre_natals;
		if (numberToLay != 0)
		{
			for (int i = counter; i < numberToLay + counter; i++)
			{

				pre_natals.push_back(new egg());

				current_pre_natals++;
			}
		}
	}
}

void anthill::printStateLog()
{
	_queen->printStateLog();
	for (warrior *e : warriors)
	{
		e->printStateLog();
	}

	for (worker *e : workers)
	{
		e->printStateLog();
	}

	std::cout << "Anthill: " << std::endl;
	std::cout << "       number of  pre_natals: " << current_pre_natals << std::endl;
	std::cout << "       current food         :" << food_quantity << "/" << food_capacity << std::endl;
}
int anthill::getahCase()
{
	return ahCase;
}

void anthill::feedAnt()
{
	food_quantity = _queen->feedQueen(food_quantity);
	for (worker *e : workers)
	{
		food_quantity = e->feedWorker(food_quantity);
	}
}

void anthill::circleOfLife()
{
	for (worker *e : workers)
	{
		if (e->maturityAttain())
		{
			warriors.push_back(new warrior());
			delete e;
		}
	}
	for (int i = 0; i < pre_natals.size(); i++)
	{
		if (pre_natals[i]->maturityAttain())
		{
			switch (pre_natals[i]->type_pre_natal())
			{
			case 1: // case larva
				workers.push_back(new worker());
				removePreNatal(pre_natals[i]);
				break;
			case 2: //case egg
				pre_natals[i] = new larva();
				break;

			default:
				break;
			}
		}
	}
}