#pragma once

#ifndef SUPERIOR_H
#define	SUPERIOR_H
#include "Libraries.h"
#include "Caracteristica.h"
#include "Ser.h"
#include "Posicao.h"


class Ser;
class Jogo;
class Caracteristica;

class Superior :public Caracteristica {


public:
	Superior(string n, int cm, int cf,int idCar);
	~Superior();

	void fazEfeito(Posicao *p, Ser *s);

};

#endif	/* SUPERIOR_H */