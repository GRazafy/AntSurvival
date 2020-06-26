#ifndef QUEEN_H_ /* Include guard */
#define QUEEN_H_

#include "../headers/ant.h"

class queen : public ant
{
private:
    int food_for_birth; // food required to lay eggs
    int current_eggs;   //number of current eggs
    int litter;         //number of eggs by turn maximum

public:
    queen();
    ~queen();

    int layEggs();
    int getAge();
    void endTurn();

    int feedQueen(int food_quantity);
    bool thresholdReached();
    int remainingRoom();
    void printStateLog();
    void decreaseEggs();

    static const int threshold_egg = 10;
};

#endif // QUEEN_H_
