#ifndef WORKER_H_ /* Include guard */
#define WORKER_H_

#include "../headers/ant.h"

class worker : public ant
{
private:
public:
    worker();
    ~worker();
    int feedWorker(int food_quantity);
    void printStateLog();
};

#endif // WARRIOR_H_