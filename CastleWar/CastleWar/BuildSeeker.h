#pragma once
#ifndef BUILDSEEKER_H
#define	BUILDSEEKER_H

#include "Caracteristica.h"


class Ser;
class Jogo;
class Edificio;
//class Caracteristica;

class BuildSeeker :public Caracteristica {


public:
	BuildSeeker(string n, int cm, int cf,int idCar);
	~BuildSeeker();

	void fazEfeito( int p, Ser *s, Jogo *jogo);

};

#endif	/* BUILDSEEKER_H */