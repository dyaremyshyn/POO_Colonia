#pragma once

#ifndef SER_H
#define	SER_H

#include "Libraries.h"
#include "Posicao.h"

class Ser;
class Edificio;
class Jogo;
class Caracteristica;
class Posicao;

class Ser {
	int pos;
	char nome;
	int custo;
	vector<Caracteristica*> caracteristicas;
	char bandeira;
	
	int saude;
	int maxSaude;
	int forca;
	int velocidade;
	int ataque;
	int defesa;
	
	bool castelo;

public:
	Ser(char n, vector<Caracteristica*>c);
	~Ser();

	char getNome();

	void setPos(int p);
	int getPos();

	void setSaude(int v);
	int getSaude();

	void setMaxSaude(int s);
	int getMaxSaude();

	void setDefesa(int d);
	int getDefesa();

	void setAtaque(int a);
	int getAtaque();

	void setVelocidade(int v);
	int getVelocidade();

	void setForca(int f);
	int getForca();

	vector<Caracteristica*> getCaracteristicas();

	void ganhaCaracteristas(Caracteristica *c);
	void calcularCusto();


	void mover();
	void efeitoCaracteristicas();


	boolean dentroCastelo();
	void setCastelo(bool c);
};
#endif	/* SER_H */