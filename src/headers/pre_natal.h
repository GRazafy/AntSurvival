#ifndef PRE_NATAL_H_ /* Include guard */
#define PRE_NATAL_H_

#include <iostream>

enum TypePreNatal
{
    EGG,
    LARVA
};

class pre_natal
{
protected:
    int maturity;
    TypePreNatal typePreNatal;

public:
    pre_natal();
    ~pre_natal();
    virtual bool maturityAttain();
    virtual int type_pre_natal();

    void endTurn();
    int getMaturity();
};

#endif // PRE_NATAL_H_