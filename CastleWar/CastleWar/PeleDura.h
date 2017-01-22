#pragma once
#ifndef PELEDURA_H
#define	PELEDURA_H

#include "Libraries.h"
#include "Caracteristica.h"
#include "Ser.h"
#include "Posicao.h"

class Ser;
class Jogo;
class Caracteristica;

class PeleDura :public Caracteristica {


public:
	PeleDura(string n, int cm, int cf,int idCar);
	~PeleDura();

	void fazEfeito(Posicao *p, Ser *s);

};

#endif	/* PELEDURA_H */