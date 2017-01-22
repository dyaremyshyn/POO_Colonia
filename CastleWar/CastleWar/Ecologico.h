#pragma once
#ifndef ECOLOGICO_H
#define	ECOLOGICO_H

#include "Libraries.h"
#include "Caracteristica.h"
#include "Ser.h"
#include "Posicao.h"

class Ser;
class Jogo;
class Caracteristica;

class Ecologico :public Caracteristica {


public:
	Ecologico(string n, int cm, int cf,int idCar);
	~Ecologico();

	void fazEfeito(Posicao *p, Ser *s);

};

#endif	/* ECOLOGICO_H */