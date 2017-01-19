#pragma once

#ifndef AGRESSAO_H
#define	AGRESSAO_H

#include "Libraries.h"
#include "Caracteristica.h"
#include "Ser.h"
#include "Posicao.h"

class Ser;
class Jogo;
class Caracteristica;
class Posicao;

class Agressao :public Caracteristica {


public:
	Agressao(string n, int cm, int cf);
	~Agressao();

	void fazEfeito(Posicao *p, Ser *s);

};

#endif	/* AGRESSAO_H */