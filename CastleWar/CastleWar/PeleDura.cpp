#include "PeleDura.h"

PeleDura::PeleDura(string n, int cm, int cf,int idCar) : Caracteristica(n, cm, cf, idCar)
{
}

PeleDura::~PeleDura()
{
}

void PeleDura::fazEfeito(int p, Ser * s)
{
	s->setDefesa(s->getDefesa() + 1);
}
