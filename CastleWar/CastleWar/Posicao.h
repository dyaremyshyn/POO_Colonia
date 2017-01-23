#pragma once
#ifndef POSICAO_H
#define	POSICAO_H
#include "Libraries.h"
#include "Edificio.h"
#include "Ser.h"
#include "Colonia.h"

class Edificio;
class Ser;

class Posicao {
	//Colonia *c;
	Edificio *e;
	Ser *s;


public:
	Edificio* getEdifico();
	void setEdificio(Edificio *e);

	Ser* getSer();
	void setSer(Ser *s);

	//char getColonia();
	//void setColonia(Colonia *c);

	//bool verificaColonia();
	bool verificaEdifico();
	bool verificaSer();

	Posicao();
	~Posicao();


};



#endif	/* POSICAO_H */