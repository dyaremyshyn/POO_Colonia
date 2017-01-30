#include "Walker.h"
#include "Ser.h"
#include "Jogo.h"

Walker::Walker(string n, int cm, int cf,int idCar) : Caracteristica(n, cm, cf, idCar) {}

Walker::~Walker()
{
}

void Walker::fazEfeito(int p, Ser *s, Jogo *jogo)
{
	if (andarDireita == true) {
		if (jogo->getMundo().at(s->getPos() + 1)->getEdifico() != nullptr || jogo->getMundo().at(s->getPos() + 1)->getSer() != nullptr) {
			s->setPos(s->getPos() + 1);
			andarDireita = true;
		}
		else andarDireita = false;
	}
	if (andarDireita == false) {
		if (jogo->getMundo().at(s->getPos() - 1)->getEdifico() != nullptr || jogo->getMundo().at(s->getPos() - 1)->getSer() != nullptr) {
			s->setPos(s->getPos() - 1);
		}
		else andarDireita = true;
	}

}


