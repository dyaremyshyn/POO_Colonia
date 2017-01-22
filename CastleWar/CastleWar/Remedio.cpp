#include "Remedio.h"

Remedio::Remedio(string n, int cm, int cf,int idCar) : Caracteristica(n, cm, cf, idCar)
{
	cont = 0;
}

Remedio::~Remedio()
{
}

void Remedio::fazEfeito(Posicao * p, Ser * s)
{
	if (s->getSaude() <= 3) {
		if (cont < 1 && s->foraCastelo()) {
			s->setSaude(s->getSaude() + 2);
		}
		else {
			s->setSaude(s->getSaude() + 2);
		}
	}
}
