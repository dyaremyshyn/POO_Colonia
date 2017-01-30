#pragma once
#ifndef ECOLOGICO_H
#define	ECOLOGICO_H

#include "Caracteristica.h"

class Ser;
class Jogo;
class Edificio;
//class Caracteristica;

class Ecologico :public Caracteristica {


public:
	Ecologico(string n, int cm, int cf,int idCar);
	~Ecologico();

	void fazEfeito(int p, Ser *s, Jogo *jogo);

};

#endif	/* ECOLOGICO_H */