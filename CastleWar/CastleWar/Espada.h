#pragma once
#ifndef ESPADA_H
#define	ESPADA_H

#include "Caracteristica.h"

class Ser;
class Jogo;
//class Caracteristica;

class Espada :public Caracteristica {
	int cont;

public:
	Espada(string n, int cm, int cf,int idCar);
	~Espada();
	void setCont(int c);
	int getCont();

	void fazEfeito(int p, Ser *s, Jogo *jogo);

};

#endif	/* ESPADA_H */