#include "Faca.h"
#include "Ser.h"
#include "Jogo.h"

Faca::Faca(string n, int cm, int cf,int idCar) : Caracteristica(n, cm, cf, idCar)
{
}

Faca::~Faca()
{
}

void Faca::fazEfeito(int p, Ser * s, Jogo *jogo)
{
	s->setAtaque(s->getAtaque() + 1);
}
