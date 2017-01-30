#pragma once

#ifndef SUPERIOR_H
#define	SUPERIOR_H

#include "Caracteristica.h"

class Ser;
class Jogo;
//class Caracteristica;

class Superior :public Caracteristica {


public:
	Superior(string n, int cm, int cf,int idCar);
	~Superior();

	void fazEfeito(int p, Ser *s, Jogo *jogo);

};

#endif	/* SUPERIOR_H */