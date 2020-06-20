#include "../headers/anthill.h"

anthill::anthill()
{
	warriors = std::vector<warrior *>();
	workers = std::vector<worker *>();
	this->_queen = new queen();
	warriors.push_back(new warrior());
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

void anthill::checkLife()
{
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
		delete _queen;
	}
}

bool anthill::checkLivingAnt()
{
	return warriors.empty() || _queen == nullptr;
}

std::vector<warrior *> anthill::getWarriors()
{
	return warriors;
}

<<<<<<< HEAD
void anthill::refill(int foodToRefill)
{
	food_quantity += foodToRefill;
}
=======
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
			for (int i = current_pre_natals + 1; i < numberToLay; i++)
			{
				pre_natals[i] = new egg();
			}
		}
	}
}

void anthill::printStateLog()
{
	_queen->printStateLog();
	for (ant *e : warriors)
	{
		e->printStateLog();
	}

	for (ant *e : workers)
	{
		e->printStateLog();
	}
}
>>>>>>> a1ec70dfbd6a50d8dfa538fbde6c84dc36c84ad3
