#pragma once
#ifndef HEATSEEKER_H
#define	HEATSEEKER_H

#include "Caracteristica.h"
class Ser;
class Jogo;
//class Caracteristica;

class HeatSeeker :public Caracteristica {


public:
	HeatSeeker(string n, int cm, int cf,int idCar);
	~HeatSeeker();

	void fazEfeito( int p, Ser *s, Jogo *jogo);

};

#endif	/* HEATSEEKER_H */