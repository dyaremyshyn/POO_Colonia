#pragma once

#ifndef CONFIGURACOES_H
#define	CONFIGURACOES_H

 
#include "Libraries.h"

using namespace std;

class Configuracoes {

	int dificuldade;
	int t, f;
	int moedas;
	
	string nome_ficheiro;
	

public:

	Configuracoes(string nome_ficheiro);
	~Configuracoes();
	
	int getDificuldade();
	int getTamanho();
	int getFoco();
	int getMoedas();

	bool leFicheiro(string nome_ficheiro);
	void getAsString()const;
};

#endif /* CONFIGURACOES_H */