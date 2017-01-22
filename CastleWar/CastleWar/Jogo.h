#ifndef MENU_H
#define	MENU_H

#include "Libraries.h"
#include "Colonia.h"
#include "Posicao.h"
#include "Castelo.h"
#include "Quinta.h"
#include "Perfil.h"

//INCLUDES DE CARACTERISTICAS
#include "Bandeira.h"
#include "Superior.h"
#include "PeleDura.h"
#include "Armadura.h"
#include "Faca.h"
#include "Espada.h"
#include "Agressao.h"
#include "Ecologico.h"
#include "HeatSeeker.h"
#include "BuildSeeker.h"
#include "Walker.h"
#include "Remedio.h"
#include "SecondChance.h"


#define TAM_MAX 20
#define F_MAX 10

class Configuracoes;
class Sala;
class Evento;
class Colonia;
class Posicao;

class Jogo{

	Configuracoes *config;
	vector <Posicao*> mundo;
	int ascii = 97;
	
	int instantes;
	bool fim_jogo;
	Colonia * myColonia;
	vector<Colonia*> opoColonia;
	int oponentes;
	vector<Perfil*> perfil;
	int iteracao;

public:

    Jogo(string fConfig);
	Jogo();
    ~Jogo();

	void addPerfil(Perfil* p);
	void addCarAoPerfil(char perfil,int idCar);
	void removeCarAoPerfil(char p, int idCar);
	void removePerfil(char p);

	void loadFicheiro(string f);
	void ComecarAJogar();

	void addPrimeirosSeres();
	void addPrimeirosEdificios();
	int escolhePosColonia(int col);
	void preencheMundo();
	Colonia* getMyColonia();

	vector <Posicao*> getMundo();
	vector<Colonia*> getOpoColonias();
	
	void Move(char u[], char o[], char d[]);
	void turno();

	void criaMundo(int dim);
	void criaMyColonia(int m);
	void criaColOponentes(int m, int o);

	void DadosJogo();
};

#endif	/* MENU_H */

