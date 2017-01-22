#pragma once
#ifndef SECONDCHANCE_H
#define	SECONDCHANCE_H

#include "Libraries.h"
#include "Caracteristica.h"
#include "Ser.h"
#include "Posicao.h"

class Ser;
class Jogo;
class Caracteristica;

class SecondChance :public Caracteristica {

public:
	SecondChance(string n, int cm, int cf,int idCar);
	~SecondChance();

	void fazEfeito(Posicao *p, Ser *s);

};

#endif	/* SECONDCHANCE_H */