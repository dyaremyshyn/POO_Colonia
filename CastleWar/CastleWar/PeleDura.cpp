#include "PeleDura.h"

PeleDura::PeleDura(string n, int cm, int cf) : Caracteristica(n, cm, cf)
{
}

PeleDura::~PeleDura()
{
}

void PeleDura::fazEfeito(Posicao * p, Ser * s)
{
	s->setDefesa(s->getDefesa() + 1);
}
