#ifndef MENU_H
#define	MENU_H

#include "Libraries.h"
#include "Colonia.h"
#include "Posicao.h"
#include "Castelo.h"
#include "Quinta.h"

#define TAM_MAX 20
#define F_MAX 10
class Configuracoes;
class Sala;
class Evento;
class Colonia;
class Posicao;

class Jogo{

	Consola c;
	Configuracoes *config;

	vector <Posicao*> mundo;
	
	int instantes;
	bool fim_jogo;
	vector<Colonia*> colonias;
	
	int iteracao;

public:

    Jogo();
    ~Jogo();

	void addPrimeirosSeres();
	void addPrimeirosEdificios();
	int escolhePosColonia(int col);
	void preencheMundo();
	vector <Posicao*> getMundo();
	vector<Colonia*> getColonias();
	
	void Move(char u[], char o[], char d[]);
	void turno();

};

#endif	/* MENU_H */

