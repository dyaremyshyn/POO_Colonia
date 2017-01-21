#pragma once

#ifndef EDIFICIO_H
#define	EDIFICIO_H
#include "Libraries.h"

class Ser;
class Jogo;

class Edificio {
	int custo;
	string nome;
	int saude;
	int defesa;
	int eid=0;

public:
	Edificio(string n, int c, int s, int d);
	~Edificio();

	string getNome();
	void setNome(string n);

	int getCusto();
	void setCusto(int c);

	int getSaude();
	void setSaude(int s);

	int getDefesa();
	void setDefesa(int d);

	int getEID();

	virtual void fazEfeito() = 0;


};
#endif	/* EDIFICIO_H */
