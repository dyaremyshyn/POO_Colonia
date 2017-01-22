#pragma once
#ifndef HEATSEEKER_H
#define	HEATSEEKER_H

#include "Libraries.h"
#include "Caracteristica.h"
#include "Ser.h"
#include "Posicao.h"

class Ser;
class Jogo;
class Caracteristica;

class HeatSeeker :public Caracteristica {


public:
	HeatSeeker(string n, int cm, int cf,int idCar);
	~HeatSeeker();

	void fazEfeito(Posicao *p, Ser *s);

};

#endif	/* HEATSEEKER_H */