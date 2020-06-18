#ifndef WARRIOR_H_ /* Include guard */
#define WARRIOR_H_

#include "../headers/ant.h"

class warrior : public ant
{
private:
    int food_capacity;
    int food_quantity;

public:
    warrior();
    ~warrior();
    void move(int x, int y);
    int getX();
    int getY();
};

#endif // WARRIOR_H_
