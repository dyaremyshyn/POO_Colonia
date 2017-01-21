#include "Torre.h"

Torre::Torre(string n, int c, int s, int d) :Edificio(n, c, s, d)
{
	nivel = 1;
}

Torre::~Torre()
{
}

void Torre::fazEfeito()
{
	
}

void Torre::aumentaNivel()
{
	nivel++;
}
