#pragma once
#ifndef FACA_H
#define	FACA_H

#include "Caracteristica.h"

class Ser;
class Jogo;
//class Caracteristica;

class Faca :public Caracteristica {


public:
	Faca(string n, int cm, int cf,int idCar);
	~Faca();

	void fazEfeito(int p, Ser *s, Jogo *jogo);

};

#endif	/* FACA_H */