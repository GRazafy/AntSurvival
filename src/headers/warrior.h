#ifndef WARRIOR_H_ /* Include guard */
#define WARRIOR_H_

#include "../headers/ant.h"

class warrior : public ant
{
private:
    int food_capacity; // food that the warrior can bring to his anthill
    int food_quantity; // food that the warrior currently have

public:
    warrior();
    ~warrior();
    void move(int x, int y);
    int getX();
    int getY();
};

#endif // WARRIOR_H_
