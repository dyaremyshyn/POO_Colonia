#include "Faca.h"

Faca::Faca(string n, int cm, int cf,int idCar) : Caracteristica(n, cm, cf, idCar)
{
}

Faca::~Faca()
{
}

void Faca::fazEfeito(int p, Ser * s)
{
	s->setAtaque(s->getAtaque() + 1);
}
