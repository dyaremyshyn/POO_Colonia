#pragma once

#ifndef CARACTERISTICA_H
#define	CARACTERISTICA_H
#include "Libraries.h"

class Ser;
class Jogo;
class Posicao;

class Caracteristica {
protected:
	string nome;
	int custo_monetario;
	int custo_forca;


	Caracteristica(string n, int cm, int cf);
	~Caracteristica();

public:

	int getCustoMonetario();
	int getCustoForça();
	virtual void fazEfeito(Posicao *p, Ser *s) = 0;
	
};
#endif	/* CARACTERISTICA_H */