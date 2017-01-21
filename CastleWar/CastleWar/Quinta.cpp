#include "Quinta.h"

Quinta::Quinta(string n, int c,int s, int d): Edificio(n,c,s,d)
{
	nivel = 1;
}

Quinta::~Quinta()
{
}

void Quinta::fazEfeito()
{
}

void Quinta::aumentaNivel()
{
	nivel++;
}
