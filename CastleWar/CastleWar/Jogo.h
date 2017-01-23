#ifndef MENU_H
#define	MENU_H

#include "Libraries.h"
#include "Colonia.h"
#include "Posicao.h"
#include "Castelo.h"
#include "Quinta.h"
#include "Perfil.h"
#include "Torre.h"

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
	char ascii;
	
	int instantes;
	bool fim_jogo;
	Colonia * myColonia;
	vector<Colonia*> opoColonia;
	int oponentes;
	vector<Perfil*> perfil;
	int iteracao;
	vector<string> comandosFicheiro;
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

	//void addPrimeirosSeres();
	void addPrimeirosEdificios();
	int escolhePosColonia(int col);
	void preencheMundo();
	Colonia* getMyColonia();

	vector <Posicao*> getMundo();
	vector<Colonia*> getOpoColonias();
	
	//FUNCOES DE CMD MODO JOGO ON
	void setMoedasNumaColonia(char c, int m);
	void buildEdif(string nomeEdif, int pos, Colonia* c);
	void listaColonia(char c);
	void mostraCarDePerfil(char c);
	void mkBuild(string e, int l, int c, char col);
	void repairBuild(int id);
	void upgradeBuild(int id);
	void sellBuild(int id);
	void criaSer(int n, char p);
	void ataca();
	void recolhe();
	bool lerComandosFicheiro(string fich);

	void turno();

	void criaMundo(int dim);
	void criaMyColonia(int m);
	void criaColOponentes(int m, int o);

	//void DadosJogo();
};

#endif	/* MENU_H */

