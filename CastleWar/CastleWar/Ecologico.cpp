#include "Ecologico.h"
#include "Ser.h"
#include "Jogo.h"
#include "Edificio.h"

Ecologico::Ecologico(string n, int cm, int cf,int idCar) : Caracteristica(n, cm, cf, idCar)
{
}

Ecologico::~Ecologico()
{
}

void Ecologico::fazEfeito(int p, Ser * s, Jogo *jogo)
{
	if (jogo->getMundo().at(p - 1)->getEdifico() != nullptr) {
		if (s->getBandeira() != jogo->getMundo().at(p - 1)->getEdifico()->getBandeira())
			jogo->getMundo().at(p - 1)->getEdifico()->setSaude(jogo->getMundo().at(p - 1)->getEdifico()->getSaude() - s->getAtaque());
	}
	if (jogo->getMundo().at(p + 1)->getEdifico() != nullptr) {
		if (s->getBandeira() != jogo->getMundo().at(p + 1)->getEdifico()->getBandeira())
			jogo->getMundo().at(p + 1)->getEdifico()->setSaude(jogo->getMundo().at(p + 1)->getEdifico()->getSaude() - s->getAtaque());
	}
}
