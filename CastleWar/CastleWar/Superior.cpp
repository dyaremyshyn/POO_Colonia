#include "Superior.h"

Superior::Superior(string n, int cm, int cf,int idCar):Caracteristica(n,cm,cf, idCar)
{
}

Superior::~Superior()
{
}

void Superior::fazEfeito(Posicao * p, Ser * s)
{
	s->setSaude(s->getSaude() + 1);
}
