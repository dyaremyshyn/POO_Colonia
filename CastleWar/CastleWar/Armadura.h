#pragma once
#ifndef ARMADURA_H
#define	ARMADURA_H

#include "Libraries.h"
#include "Caracteristica.h"
#include "Ser.h"
#include "Posicao.h"

class Ser;
class Jogo;
class Caracteristica;

class Armadura :public Caracteristica {


public:
	Armadura(string n, int cm, int cf);
	~Armadura();

	void fazEfeito(Posicao *p, Ser *s);

};

#endif	/* ARMADURA_H */