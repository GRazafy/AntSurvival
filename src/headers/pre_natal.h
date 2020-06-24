#ifndef PRE_NATAL_H_ /* Include guard */
#define PRE_NATAL_H_

#include <iostream>

class pre_natal
{
protected:
    int maturity;

public:
    pre_natal();
    ~pre_natal();
    virtual bool maturityAttain();
    virtual int type_pre_natal();
};

#endif // PRE_NATAL_H_