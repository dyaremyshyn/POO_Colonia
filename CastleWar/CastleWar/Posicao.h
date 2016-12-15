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
	Colonia *c;
	Edificio *e;
	Ser *s;


public:
	string getEdifico();
	void setEdificio(Edificio *e);
	string getSer();
	void setSer(Ser *s);
	string getColonia();
	void setColonia(Colonia *c);
	bool verificaColonia();
	bool verificaEdifico();
	bool verificaSer();

	Posicao();
	~Posicao();


};



#endif	/* POSICAO_H */