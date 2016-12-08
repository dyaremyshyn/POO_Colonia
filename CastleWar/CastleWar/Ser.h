#pragma once

#ifndef SER_H
#define	SER_H
#include "Libraries.h"

class Ser;
class Edificio;
class Jogo;
class Caracteristica;

class Ser {
	int custo;
	vector<Caracteristica*> caracteristicas;


public:
	Ser();
	~Ser();


};
#endif	/* SER_H */