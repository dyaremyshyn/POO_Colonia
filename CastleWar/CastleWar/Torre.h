#pragma once

#ifndef TORRE_H
#define	TORRE_H

#include "Edificio.h"
//class Ser;
class Jogo;
//class Edificio;

class Torre : public Edificio {
	int custo;
	string nome;
	int ataque;

public:
	Torre(char n, char b, int c, int s, int d);
	~Torre();

	int getAtaque();
	void setAtaque(int a);
	void fazEfeito(Jogo *jogo);
	void upgrade();
};
#endif	/* TORRE_H */