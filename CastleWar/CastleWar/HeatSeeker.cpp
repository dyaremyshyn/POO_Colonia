#include "HeatSeeker.h"
#include "Ser.h"
#include "Jogo.h"

HeatSeeker::HeatSeeker(string n, int cm, int cf,int idCar) : Caracteristica(n, cm, cf, idCar)
{
}

HeatSeeker::~HeatSeeker()
{
}

void HeatSeeker::fazEfeito(int p, Ser * s, Jogo *jogo)
{

	if (jogo->getMundo().at(s->getPos() + 1)->getSer()->getBandeira() != s->getBandeira())
		jogo->getMundo().at(s->getPos() + 1)->getSer()->setSaude(jogo->getMundo().at(s->getPos() + 1)->getSer()->getSaude() - s->getAtaque());
	else
		s->setPos(s->getPos() + 1);
}
