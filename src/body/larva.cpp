#include "../headers/larva.h"

larva::larva()
{
	maturity = 0;
}

larva::~larva()
{
}

bool larva::maturityAttain()
{
	return maturity == ageForWorker;
}

int larva::type_pre_natal()
{
	return 1;
}