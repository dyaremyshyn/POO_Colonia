#include "Agressao.h"
#include "Ser.h"
#include "Jogo.h"

Agressao::Agressao(string n, int cm, int cf,int idCar) : Caracteristica(n, cm, cf, idCar)
{
}

Agressao::~Agressao()
{
}

void Agressao::fazEfeito(int p, Ser * s, Jogo *jogo)
{
	if (jogo->getMundo().at(p - 1)->getSer() != nullptr) {
		if (s->getBandeira() != jogo->getMundo().at(p - 1)->getSer()->getBandeira())
			jogo->getMundo().at(p - 1)->getSer()->setSaude(jogo->getMundo().at(p - 1)->getSer()->getSaude() - s->getAtaque());
	}
	if (jogo->getMundo().at(p + 1)->getSer() != nullptr) {
		if (s->getBandeira() != jogo->getMundo().at(p + 1)->getSer()->getBandeira())
			jogo->getMundo().at(p + 1)->getSer()->setSaude(jogo->getMundo().at(p + 1)->getSer()->getSaude() - s->getAtaque());
	}
}
