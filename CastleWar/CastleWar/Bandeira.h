#pragma once

#ifndef BANDEIRA_H
#define	BANDEIRA_H

#include "Caracteristica.h"

//class Caracteristica;
class Ser;
class Jogo;


class Bandeira :public Caracteristica {
	

public:
	Bandeira(string n, int cm, int cf,int idCar);
	~Bandeira();
	
	void fazEfeito(int p, Ser *s, Jogo *jogo);

};

#endif	/* BANDEIRA_H */