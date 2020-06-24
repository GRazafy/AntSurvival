#ifndef ANTHILL_H_ /* Include guard */
#define ANTHILL_H_

#include "queen.h"
#include "warrior.h"
#include "worker.h"
#include "pre_natal.h"
#include "egg.h"
#include "larva.h"
#include <iostream>
#include <vector>

class anthill
{
private:
	int pop_max;
	int food_quantity;
	int food_capacity;
	int current_pre_natals;
	int ahCase; //square of anthill

	queen *_queen;
	std::vector<warrior *> warriors;
	std::vector<worker *> workers;
	std::vector<pre_natal *> pre_natals;

	//pheromone
public:
	anthill(int ahcase);
	~anthill();
	bool checkLife();
	bool checkLivingAnt();
	void refill(warrior *myWarrior);
	void layEggs();
	void feedAnt();
	int getahCase();

	void printStateLog();
	void circleOfLife();

	void removeWarrior(warrior *e);
	void removeWorker(worker *e);
	void removePreNatal(pre_natal *e);
	std::vector<warrior *> getWarriors();
};

#endif // ANTHILL_H_