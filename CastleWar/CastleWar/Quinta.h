#pragma once

#ifndef QUINTA_H
#define	QUINTA_H

#include "Edificio.h"

//class Ser;
//class Jogo;
//class Edificio;

class Quinta : public Edificio {
	int custo;
	string nome;
	int fabricaMoedas;

public:
	Quinta(char n, char b, int c, int s, int d);
	~Quinta();

	void fazEfeito(Jogo *jogo);
	void upgrade();

	void setFabricaMoedas(int m);
	int getFabricaMoedas();

};
#endif	/* QUINTA_H */
