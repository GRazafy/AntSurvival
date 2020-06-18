#include "../headers/anthill.h"

anthill::anthill()
{
	warriors = std::vector<warrior *>();
	workers = std::vector<worker *>();
	this->_queen = new queen();
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

void anthill::checkLife()
{
	for (ant *e : warriors)
	{
		e->
	}
}

std::vector<warrior *> anthill::getWarriors()
{
	return warriors;
}
