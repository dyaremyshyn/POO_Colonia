#pragma once

#ifndef AGRESSAO_H
#define	AGRESSAO_H

#include"Caracteristica.h"

class Jogo;
class Ser;

class Agressao :public Caracteristica {


public:
	Agressao(string n, int cm, int cf,int idCar);
	~Agressao();

	void fazEfeito(int p, Ser *s, Jogo *jogo);

};

#endif	/* AGRESSAO_H */