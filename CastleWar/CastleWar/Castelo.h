#pragma once

#ifndef CASTELO_H
#define	CASTELO_H

#include "Edificio.h"


//class Ser;
//class Jogo;
//class Edificio;
class Castelo: public Edificio {
	int custo;
	string nome;
	vector<Ser*> seres;

public:
	Castelo(char n, char b, int c, int s, int d);
	~Castelo();
	
	void fazEfeito(Jogo *jogo);
	void upgrade();

};
#endif	/* CASTELO_H */
