#pragma once
#ifndef BUILDSEEKER_H
#define	BUILDSEEKER_H

#include "Libraries.h"
#include "Caracteristica.h"
#include "Ser.h"
#include "Posicao.h"

class Ser;
class Jogo;
class Caracteristica;

class BuildSeeker :public Caracteristica {


public:
	BuildSeeker(string n, int cm, int cf,int idCar);
	~BuildSeeker();

	void fazEfeito(Posicao *p, Ser *s);

};

#endif	/* BUILDSEEKER_H */