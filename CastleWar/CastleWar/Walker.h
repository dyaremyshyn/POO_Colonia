#pragma once

#ifndef WALKER_H
#define	WALKER_H

#include "Caracteristica.h"
class Ser;
class Jogo;
//class Caracteristica;

class Walker :public Caracteristica {
	bool andarDireita = true;

public:
	Walker(string n, int cm, int cf,int idCar);
	~Walker();

	void fazEfeito(int p, Ser *s, Jogo *jogo);

};

#endif	/* WALKER_H */