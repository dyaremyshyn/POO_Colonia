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
	vector<Ser*> seres;

public:
	Castelo(string n, int c, int s, int d);
	~Castelo();
	
	void fazEfeito();

};
#endif	/* CASTELO_H */
