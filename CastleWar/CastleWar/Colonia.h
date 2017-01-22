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
	
	char nome;
	int moedas;
	int tamanho;
	int posInicial;

	vector<Edificio*> edificios;
	vector<Ser*> seres;
	int iteracao;

public:
	Colonia(char n, int m);
	~Colonia();

	char getNome();
	void fazAccao();
	int getTam();
	void setPosInicial(int x);
	int getPosInicial();

	void listaColonia();

};

#endif	/* COLONIA_H */