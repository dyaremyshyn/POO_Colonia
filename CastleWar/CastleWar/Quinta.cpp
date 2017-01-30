#include "Quinta.h"

Quinta::Quinta(char n, char b, int c,int s, int d): Edificio(n,b,c,s,d)
{
	fabricaMoedas = 2;
}

Quinta::~Quinta()
{
}

void Quinta::fazEfeito(Jogo *jogo)
{
	jogo->getMyColonia()->setMoedas(jogo->getMyColonia()->getMoedas() + fabricaMoedas);
}

void Quinta::upgrade()
{
	setDefesa(getDefesa() + 1);
	setFabricaMoedas(getFabricaMoedas() + 1);
	aumentaNivel();
}

void Quinta::setFabricaMoedas(int m)
{
	fabricaMoedas = m;
}

int Quinta::getFabricaMoedas()
{
	return fabricaMoedas;
}


