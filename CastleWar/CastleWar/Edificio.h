#pragma once

#ifndef EDIFICIO_H
#define	EDIFICIO_H
#include "Libraries.h"
#include "Jogo.h"
#include "Posicao.h"
#include "Ser.h"
#include "Colonia.h"

class Ser;
class Jogo;

class Edificio {
	int custo;
	char nome;
	int saude;
	int defesa;
	int pos;
	int eid=0;
	int nivel;
	char bandeira;

public:
	Edificio(char n, char b, int c, int s, int d);
	~Edificio();

	char getNome();
	void setNome(char n);

	char getBandeira();
	void setBandeira(char b);
	
	int getNivel();
	void setNivel(int n);

	int getPos();
	void setPos(int p);

	int getCusto();
	void setCusto(int c);

	int getSaude();
	void setSaude(int s);

	int getDefesa();
	void setDefesa(int d);

	int getEID();

	virtual void fazEfeito(Jogo *jogo) = 0;
	virtual void upgrade() = 0;

	void aumentaNivel();


};
#endif	/* EDIFICIO_H */
