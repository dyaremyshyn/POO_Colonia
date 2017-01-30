#include "Torre.h"

Torre::Torre(char n, char b, int c, int s, int d) :Edificio(n,b, c, s, d)
{
	ataque = 2;
}

Torre::~Torre()
{
}

int Torre::getAtaque()
{
	return ataque;
}

void Torre::setAtaque(int a)
{
	ataque = a;
}

void Torre::fazEfeito(Jogo *jogo)
{
	if (jogo->getMundo().at(getPos() - 2)->getSer() != nullptr)
		jogo->getMundo().at(getPos() - 2)->getSer()->setSaude(jogo->getMundo().at(getPos() - 2)->getSer()->getSaude() - ataque);
	if (jogo->getMundo().at(getPos() - 1)->getSer() != nullptr)
		jogo->getMundo().at(getPos() - 1)->getSer()->setSaude(jogo->getMundo().at(getPos() - 1)->getSer()->getSaude() - ataque);
	if (jogo->getMundo().at(getPos() + 2)->getSer() != nullptr)
		jogo->getMundo().at(getPos() + 2)->getSer()->setSaude(jogo->getMundo().at(getPos() + 2)->getSer()->getSaude() - ataque);
	if (jogo->getMundo().at(getPos() +1)->getSer() != nullptr)
		jogo->getMundo().at(getPos() +1)->getSer()->setSaude(jogo->getMundo().at(getPos() +1)->getSer()->getSaude() - ataque);
}

void Torre::upgrade()
{
	setDefesa(getDefesa() + 2);
	setAtaque(getAtaque() + 1);
	aumentaNivel();
}

