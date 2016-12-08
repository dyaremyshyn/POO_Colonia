#pragma once
#ifndef COLONIA_H
#define	COLONIA_H
#include "Libraries.h"

class Ser;
class Edificio;
class Jogo;

/*
COLONIA recebe acções:
	atacar
	fugir
	fazer edificio
	vender edificio
	fazer seres
*/
class Colonia {
	
	Consola c;
	
	string nome;
	int moedas;
	int tamanho[5][5];
	vector<Edificio*> edificios;
	vector<Ser*> seres;
	int iteracao;

public:
	Colonia(string n, int m);
	~Colonia();

	void fazAccao();

};

#endif	/* COLONIA_H */