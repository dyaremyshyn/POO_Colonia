#include "Armadura.h"

Armadura::Armadura(string n, int cm, int cf,int idCar) : Caracteristica(n, cm, cf, idCar)
{
}

Armadura::~Armadura()
{
}

void Armadura::fazEfeito(int p, Ser * s)
{
	s->setDefesa(s->getDefesa() + 2);
}
