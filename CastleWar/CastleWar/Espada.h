#pragma once
#ifndef ESPADA_H
#define	ESPADA_H

#include "Libraries.h"
#include "Caracteristica.h"
#include "Ser.h"
#include "Posicao.h"

class Ser;
class Jogo;
class Caracteristica;

class Espada :public Caracteristica {
	int cont;

public:
	Espada(string n, int cm, int cf,int idCar);
	~Espada();
	void setCont(int c);
	int getCont();

	void fazEfeito(int p, Ser *s);

};

#endif	/* ESPADA_H */