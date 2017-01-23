#include "Espada.h"

Espada::Espada(string n, int cm, int cf,int idCar) : Caracteristica(n, cm, cf, idCar)
{
	cont = 0;
}

Espada::~Espada()
{
}

void Espada::setCont(int c)
{
	cont = c;
}

int Espada::getCont()
{
	return cont;
}

void Espada::fazEfeito(int p, Ser * s)
{
	if (getCont() < 2) {
		s->setAtaque(s->getAtaque() + 3);
	}
	else {
		s->setAtaque(s->getAtaque() + 2);
	}

}
