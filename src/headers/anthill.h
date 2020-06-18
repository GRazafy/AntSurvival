#ifndef ANTHILL_H_ /* Include guard */
#define ANTHILL_H_

#include "queen.h"
#include "warrior.h"
#include "worker.h"
#include <iostream>
#include <vector>

class anthill
{
private:
	int pop_max;
	int food_quantity;
	queen* _queen;
	std::vector<warrior*> warriors;
	std::vector<worker*> workers;
	//pheromone
public:
	anthill();
	~anthill();
	void initi();
};

#endif // ANTHILL_H_