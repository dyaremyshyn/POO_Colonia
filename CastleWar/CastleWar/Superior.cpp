#include "Superior.h"

Superior::Superior(string n, int cm, int cf):Caracteristica(n,cm,cf)
{
}

Superior::~Superior()
{
}

void Superior::fazEfeito(Posicao * p, Ser * s)
{
	s->setSaude(s->getSaude() + 1);
}
