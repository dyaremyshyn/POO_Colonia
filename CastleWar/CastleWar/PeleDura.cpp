#include "PeleDura.h"
#include "Ser.h"
#include "Jogo.h"

PeleDura::PeleDura(string n, int cm, int cf,int idCar) : Caracteristica(n, cm, cf, idCar)
{
}

PeleDura::~PeleDura()
{
}

void PeleDura::fazEfeito(int p, Ser * s, Jogo *jogo)
{
	s->setDefesa(s->getDefesa() + 1);
}
