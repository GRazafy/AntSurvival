#ifndef WORKER_H_ /* Include guard */
#define WORKER_H_

#include "../headers/ant.h"

const int ageForWarrior = 30;

class worker : public ant
{
private:
public:
    worker();
    ~worker();
    int feedWorker(int food_quantity);
    void printStateLog();
    bool maturityAttain();
};

#endif // WARRIOR_H_