#ifndef QUEEN_H_   /* Include guard */
#define QUEEN_H_

#include "../headers/ant.h"

class queen : public ant{
    private:
       int food_for_birth;
       int threshold_egg;
    public:
        queen();
        ~queen();
};

#endif // QUEEN_H_
