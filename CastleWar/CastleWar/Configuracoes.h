#pragma once

#ifndef CONFIGURACOES_H
#define	CONFIGURACOES_H

 
#include "Libraries.h"

using namespace std;

class Configuracoes {

	int lin, col;
	int oponentes;
	int moedas;
	
	string nome_ficheiro;
	

public:

	Configuracoes(string nome_ficheiro);
	~Configuracoes();
	
	int getCol();
	int getLin();
	
	int getMoedas();
	int getOponentes();

	bool leFicheiro(string nome_ficheiro);
	//void getAsString()const;
};

#endif /* CONFIGURACOES_H */