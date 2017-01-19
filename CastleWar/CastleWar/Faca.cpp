#include "Faca.h"

Faca::Faca(string n, int cm, int cf) : Caracteristica(n, cm, cf)
{
}

Faca::~Faca()
{
}

void Faca::fazEfeito(Posicao * p, Ser * s)
{
	s->setAtaque(s->getAtaque() + 1);
}
