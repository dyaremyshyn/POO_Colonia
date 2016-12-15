#pragma once

#ifndef SER_H
#define	SER_H
#include "Libraries.h"

class Ser;
class Edificio;
class Jogo;
class Caracteristica;

class Ser {
	string nome;
	int custo;
	vector<Caracteristica*> caracteristicas;
	string bandeira;
	int saude;
	int defesa;
	int ataque;

public:
	Ser(string n, int nCar);
	Ser(string n, int nCar, vector<Caracteristica*> c);
	~Ser();

	string getNome();
	void setSaude(int v);
	int getSaude();
	void setDefesa(int d);
	int getDefesa();
	void setAtaque(int a);
	int getAtaque();
	void ganhaCaracteristas(Caracteristica *c);
	void calcularCusto();
};
#endif	/* SER_H */