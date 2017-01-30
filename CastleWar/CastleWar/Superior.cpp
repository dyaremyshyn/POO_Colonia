#include "Superior.h"
#include "Ser.h"
#include "Jogo.h"

Superior::Superior(string n, int cm, int cf,int idCar):Caracteristica(n,cm,cf, idCar)
{
}

Superior::~Superior()
{
}

void Superior::fazEfeito(int p, Ser * s, Jogo *jogo)
{
	s->setSaude(s->getSaude() + 1);
}
