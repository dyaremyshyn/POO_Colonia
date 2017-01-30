#include "BuildSeeker.h"
#include "Ser.h"
#include "Jogo.h"
#include "Edificio.h"

BuildSeeker::BuildSeeker(string n, int cm, int cf,int idCar) : Caracteristica(n, cm, cf, idCar)
{
}

BuildSeeker::~BuildSeeker()
{
}

void BuildSeeker::fazEfeito(int p, Ser * s, Jogo *jogo)
{
	if (jogo->getMundo().at(s->getPos() + 1)->getEdifico()->getBandeira() != s->getBandeira())
		jogo->getMundo().at(s->getPos() + 1)->getEdifico()->setSaude(jogo->getMundo().at(s->getPos() + 1)->getEdifico()->getSaude() - s->getAtaque());
	else
		s->setPos(s->getPos() + 1);
}
