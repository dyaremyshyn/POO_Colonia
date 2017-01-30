#include "Remedio.h"
#include "Ser.h"
#include "Jogo.h"

Remedio::Remedio(string n, int cm, int cf,int idCar) : Caracteristica(n, cm, cf, idCar)
{
	cont = 0;
}

Remedio::~Remedio()
{
}

void Remedio::fazEfeito(int p, Ser * s, Jogo *jogo)
{
	if (s->getSaude() <= 3) {
		if (cont < 1 && !s->dentroCastelo()) {
			if (s->getSaude()<s->getMaxSaude())
				s->setSaude(s->getSaude() + 2);
		}
		else {
			if(s->getSaude()<s->getMaxSaude())
				s->setSaude(s->getSaude() + 2);
		}
	}
}
