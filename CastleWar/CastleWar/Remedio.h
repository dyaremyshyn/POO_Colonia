#pragma once
#ifndef REMEDIO_H
#define	REMEDIO_H

#include "Libraries.h"
#include "Caracteristica.h"
#include "Ser.h"
#include "Posicao.h"

class Ser;
class Jogo;
class Caracteristica;

class Remedio :public Caracteristica {
	int cont;

public:
	Remedio(string n, int cm, int cf);
	~Remedio();

	void fazEfeito(Posicao *p, Ser *s);

};

#endif	/* REMEDIO_H */