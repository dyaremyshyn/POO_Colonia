#pragma once
#ifndef FACA_H
#define	FACA_H

#include "Libraries.h"
#include "Caracteristica.h"
#include "Ser.h"
#include "Posicao.h"

class Ser;
class Jogo;
class Caracteristica;

class Faca :public Caracteristica {


public:
	Faca(string n, int cm, int cf,int idCar);
	~Faca();

	void fazEfeito(int p, Ser *s);

};

#endif	/* FACA_H */