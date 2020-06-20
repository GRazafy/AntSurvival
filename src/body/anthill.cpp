#include "../headers/anthill.h"

anthill::anthill()
{
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
			std::cout << "an ant is dead..." << std::endl;
			remove(e);
			delete e;
		}
	}
}

bool anthill::checkLivingAnt()
{
	return warriors.empty();
}

std::vector<warrior *> anthill::getWarriors()
{
	return warriors;
}
