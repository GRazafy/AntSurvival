#include "../headers/pre_natal.h"

pre_natal::pre_natal() : maturity(1)
{
        //new egg
}

pre_natal::~pre_natal()
{
}

bool pre_natal::maturityAttain()
{
        std::cout << "THIS SHOULDN'T APPEAR" << std::endl;
}

int pre_natal::type_pre_natal()
{
        std::cout << "THIS SHOULDN'T APPEAR" << std::endl;
        return -1;
}