#pragma once

#ifndef TORRE_H
#define	TORRE_H
#include "Libraries.h"
#include "Edificio.h"

class Ser;
class Jogo;

class Torre : public Edificio {
	int custo;
	string nome;


public:
	Torre(char n, int c, int s, int d);
	~Torre();

	void fazEfeito();

};
#endif	/* TORRE_H */