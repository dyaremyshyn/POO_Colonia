#pragma once

#ifndef CASTELO_H
#define	CASTELO_H
#include "Libraries.h"
#include "Edificio.h"

class Ser;
class Jogo;

class Castelo: public Edificio {
	int custo;
	string nome;

public:
	Castelo(string n, int c);
	~Castelo();

	void fazEfeito();

};
#endif	/* CASTELO_H */
