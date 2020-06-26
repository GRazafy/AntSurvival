#include "../headers/egg.h"

egg::egg()
{
	maturity = 0;
	typePreNatal = TypePreNatal::EGG;
}

egg::~egg()
{
}

bool egg::maturityAttain()
{
	return maturity == ageForLarva;
}

int egg::type_pre_natal()
{
	return typePreNatal;
}