#pragma once
#ifndef ARMADURA_H
#define	ARMADURA_H

#include "Caracteristica.h"

class Ser;
class Jogo;
//class Caracteristica;

class Armadura :public Caracteristica {


public:
	Armadura(string n, int cm, int cf,int idCar);
	~Armadura();

	void fazEfeito(int p, Ser *s, Jogo *jogo);

};

#endif	/* ARMADURA_H */