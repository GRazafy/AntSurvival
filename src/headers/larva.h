#ifndef LARVA_H_ /* Include guard */
#define LARVA_H_

#include "../headers/pre_natal.h"

const int ageForWorker = 10;

class larva : public pre_natal
{
private:
public:
    larva();
    ~larva();
    bool maturityAttain();
    int type_pre_natal();
};

#endif // LARVA_H_