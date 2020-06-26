#include "../headers/larva.h"

larva::larva()
{
	maturity = 5;
	typePreNatal = TypePreNatal::LARVA;
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
	return typePreNatal;
}