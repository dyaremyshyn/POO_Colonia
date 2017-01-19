#pragma once

#ifndef SER_H
#define	SER_H

#include "Libraries.h"

class Ser;
class Edificio;
class Jogo;
class Caracteristica;

class Ser {
	Posicao *pos;
	string nome;
	int custo;
	vector<Caracteristica*> caracteristicas;
	string bandeira;
	
	int saude;
	int forca;
	int velocidade;
	int ataque;
	int defesa;
	

public:
	Ser(string n, int nCar);
	~Ser();

	string getNome();

	void setSaude(int v);
	int getSaude();

	void setDefesa(int d);
	int getDefesa();

	void setAtaque(int a);
	int getAtaque();

	void setVelocidade(int v);
	int getVelocidade();

	void setForca(int f);
	int getForca();

	void ganhaCaracteristas(Caracteristica *c);
	void calcularCusto();

	void efeitoCaracteristicas();

	boolean foraCastelo();

};
#endif	/* SER_H */