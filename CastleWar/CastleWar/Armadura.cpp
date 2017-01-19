#include "Armadura.h"

Armadura::Armadura(string n, int cm, int cf) : Caracteristica(n, cm, cf)
{
}

Armadura::~Armadura()
{
}

void Armadura::fazEfeito(Posicao * p, Ser * s)
{
	s->setDefesa(s->getDefesa() + 2);
}
