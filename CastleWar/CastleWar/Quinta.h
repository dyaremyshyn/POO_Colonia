#pragma once

#ifndef QUINTA_H
#define	QUINTA_H
#include "Libraries.h"
#include "Edificio.h"

class Ser;
class Jogo;

class Quinta : public Edificio {
	int custo;
	string nome;

public:
	Quinta(string n, int c);
	~Quinta();

};
#endif	/* QUINTA_H */
