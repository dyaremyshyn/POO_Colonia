#include "Bandeira.h"
#include "Ser.h"
#include "Jogo.h"

Bandeira::Bandeira(string n, int cm, int cf,int idCar): Caracteristica(n, cm, cf, idCar){}

Bandeira::~Bandeira()
{
}


void Bandeira::fazEfeito(int p, Ser *s, Jogo *jogo)
{
	jogo->getMundo().at(p)->getSer()->setBandeira(jogo->getMyColonia()->getNome());
}
