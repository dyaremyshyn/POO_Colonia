#pragma once
#ifndef ALUNO_H
#define	ALUNO_H

#include "Libraries.h"
#include "Caracteristica.h"

class Ser;
class Jogo;
class Caracteristica;

class Aluno :public Caracteristica {


public:
	Aluno(string n, int cm, int cf,int idCar);
	~Aluno();

	void fazEfeito(int p, Ser *s);

};

#endif	/* ALUNO_H */