#include "../headers/anthill.h"

anthill::anthill()
{
	ahCase = 2525;
	warriors = std::vector<warrior *>();
	workers = std::vector<worker *>();
	this->_queen = new queen();
	warriors.push_back(new warrior());
	// warriors.push_back(new warrior());
	// warriors.push_back(new warrior());
	// warriors.push_back(new warrior());
	// warriors.push_back(new warrior());
	workers.push_back(new worker());

	food_capacity = 2000;
	food_quantity = 250;
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
}

void anthill::remove(warrior *e)
{
	for (std::vector<warrior *>::iterator i = warriors.begin(); i != warriors.end(); ++i)
	{
		if (*i == e)
		{
			warriors.erase(i--);
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
			remove(e);
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

	return warriors.empty() || queenDead;
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
	std::cout << "quantité dans la fourmilière " << food_quantity << std::endl;
	food_quantity += quantity;
	std::cout << "quantité dans la fourmilière " << food_quantity << std::endl;
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
		if (numberToLay != 0)
		{
			for (int i = current_pre_natals; i < numberToLay; i++)
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

	for (ant *e : workers)
	{
		e->printStateLog();
	}

	std::cout << "Anthill: " << std::endl;
	std::cout << "       number of  pre_natals: " << current_pre_natals << std::endl;
	std::cout << "       current food         :" << food_quantity << std::endl;
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