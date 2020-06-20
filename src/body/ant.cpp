#include "../headers/ant.h"

ant::ant() : age(0), max_age(100), x(50), y(25)
{
}

ant::~ant()
{
}

bool ant::endFood(){
    return food_level == 0;
}

bool ant::ageMax(){
    return age == max_age;
}

void ant::endTurn(){
    food_level -= 1;
    age += 1;
}

