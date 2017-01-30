#include "Armadura.h"
#include "Ser.h"
#include "Jogo.h"

Armadura::Armadura(string n, int cm, int cf,int idCar) : Caracteristica(n, cm, cf, idCar)
{
}

Armadura::~Armadura()
{
}

void Armadura::fazEfeito(int p, Ser * s, Jogo *jogo)
{
	s->setDefesa(s->getDefesa() + 2);
}
