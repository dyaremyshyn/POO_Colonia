#pragma once
#ifndef REMEDIO_H
#define	REMEDIO_H

#include "Caracteristica.h"
class Ser;
class Jogo;
//class Caracteristica;

class Remedio :public Caracteristica {
	int cont;

public:
	Remedio(string n, int cm, int cf,int idCar);
	~Remedio();

	void fazEfeito(int p, Ser *s, Jogo *jogo);

};

#endif	/* REMEDIO_H */