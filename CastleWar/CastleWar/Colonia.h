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

#define TAM 5

class Colonia {
	
	Consola c;
	
	string nome;
	int moedas;
	int tamanho;
	int posInicial;

	vector<Edificio*> edificios;
	vector<Ser*> seres;
	int iteracao;

public:
	Colonia(string n, int m);
	~Colonia();

	string getNome();
	void fazAccao();
	int getTam();
	void setPosInicial(int x);
	int getPosInicial();

};

#endif	/* COLONIA_H */