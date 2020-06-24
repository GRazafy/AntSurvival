#ifndef EGG_H_ /* Include guard */
#define EGG_H_

#include "../headers/pre_natal.h"

const int ageForLarva = 5;

class egg : public pre_natal
{
private:
public:
    egg();
    ~egg();
    bool maturityAttain();
    int type_pre_natal();
};

#endif // EGG_H_