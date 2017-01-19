#pragma once

#ifndef WALKER_H
#define	WALKER_H
#include "Libraries.h"
#include "Caracteristica.h"
#include "Ser.h"
#include "Posicao.h"

class Ser;
class Jogo;
class Caracteristica;

class Walker :public Caracteristica {


public:
	Walker(string n, int cm, int cf);
	~Walker();

	void fazEfeito(Posicao *p, Ser *s);

};

#endif	/* WALKER_H */