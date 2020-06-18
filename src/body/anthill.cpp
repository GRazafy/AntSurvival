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

void anthill::initi()
{
	// warriors.clear();
	// workers.clear();
	std::cout << "init running";
	// this->_queen = new queen();
	// warriors.push_back(new warrior());
	// workers.push_back(new worker());
}
std::vector<warrior *> anthill::getWarriors()
{
	return warriors;
}
