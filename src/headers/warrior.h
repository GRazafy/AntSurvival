#ifndef WARRIOR_H_ /* Include guard */
#define WARRIOR_H_

#include <vector>
#include <iostream>
#include "../headers/ant.h"
#include "../headers/square.h"

class warrior : public ant
{
private:
    static int nextID;
    int food_capacity; // food that the warrior can bring to his anthill
    int food_quantity; // food that the warrior currently have
    std::vector<int> path;
    square *last_food_square;

public:
    int id;
    warrior();
    ~warrior();
    void move(int x, int y);
    int getX();
    int getY();
    bool getfood_state();
    void addCase(int bestCase);
    int lastCase();
    void deleteLast();
    void getFood(square *e);
    int foodDeposit();
    void printStateLog();
};

#endif // WARRIOR_H_
