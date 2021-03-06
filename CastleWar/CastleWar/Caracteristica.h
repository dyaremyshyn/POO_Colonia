#pragma once

#ifndef CARACTERISTICA_H
#define	CARACTERISTICA_H
#include "Libraries.h"


class Jogo;
class Ser;

class Caracteristica {
protected:
	string nome;
	int custo_monetario;
	int custo_forca;
	int id;

	Caracteristica(string n, int cm, int cf,int idCar);
	~Caracteristica();

public:
	string getNome();

	int getCustoMonetario();
	int getCustoForça();
	virtual void fazEfeito(int p, Ser *s,Jogo *jogo) = 0;
	int getID();
	
};
#endif	/* CARACTERISTICA_H */