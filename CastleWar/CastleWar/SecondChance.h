#pragma once
#ifndef SECONDCHANCE_H
#define	SECONDCHANCE_H

#include "Caracteristica.h"
class Ser;
class Jogo;
//class Caracteristica;

class SecondChance :public Caracteristica {

public:
	SecondChance(string n, int cm, int cf,int idCar);
	~SecondChance();

	void fazEfeito(int p, Ser *s, Jogo *jogo);

};

#endif	/* SECONDCHANCE_H */