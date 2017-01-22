#pragma once

#ifndef BANDEIRA_H
#define	BANDEIRA_H
#include "Libraries.h"
#include "Caracteristica.h"

class Ser;
class Jogo;
class Caracteristica;

class Bandeira :public Caracteristica {
	

public:
	Bandeira(string n, int cm, int cf,int idCar);
	~Bandeira();
	
	void fazEfeito(Posicao *p, Ser *s);                 

};

#endif	/* BANDEIRA_H */