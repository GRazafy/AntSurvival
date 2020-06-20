#ifndef QUEEN_H_ /* Include guard */
#define QUEEN_H_

#include "../headers/ant.h"

class queen : public ant
{
private:
    int food_for_birth; // food required to lay eggs
    int threshold_egg;  //number max of current eggs
    int current_eggs;   //number of current eggs
    int litter;         //number of eggs by turn maximum

public:
    queen();
    ~queen();

    int layEggs();
    int getAge();
    void endTurn();
    bool thresholdReached();
    int remainingRoom();
    void printStateLog();
};

#endif // QUEEN_H_
