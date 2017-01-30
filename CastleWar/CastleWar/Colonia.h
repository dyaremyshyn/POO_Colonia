#pragma once
#ifndef COLONIA_H
#define	COLONIA_H
#include "Libraries.h"
//#include "Edificio.h"

class Ser;
class Edificio;
class Jogo;
class Castelo;

/*
COLONIA recebe acções:
	atacar
	fugir
	fazer edificio
	vender edificio
	fazer seres
*/


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

	vector<Edificio*> getEdificios();
	vector<Ser*> getSeres();


	char getNome();
	void fazAccao();
	int getTam();
	void setPosInicial(int x);
	int getPosInicial();
	void setMoedas(int m);
	int getMoedas();
	void addEdificio(Edificio *e);
	void removeEdificio(int id);
	void addSer(Ser* s);

	int saudeCastelo();
};

#endif	/* COLONIA_H */