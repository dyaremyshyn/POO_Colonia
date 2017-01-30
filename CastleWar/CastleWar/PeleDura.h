#pragma once
#ifndef PELEDURA_H
#define	PELEDURA_H

#include "Caracteristica.h"
class Ser;
class Jogo;
//class Caracteristica;

class PeleDura :public Caracteristica {


public:
	PeleDura(string n, int cm, int cf,int idCar);
	~PeleDura();

	void fazEfeito(int p, Ser *s, Jogo *jogo);

};

#endif	/* PELEDURA_H */