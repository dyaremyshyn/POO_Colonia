#ifndef MENU_H
#define	MENU_H

#include "Libraries.h"

class Sala;
class Evento;
class Colonia;

class Jogo{
	Consola c;
    int dificuldade;
	int tamanho[20][20];
	int foco[10][10];                                                                                                                           
	int instantes;
	bool fim_jogo;
	vector<Colonia*> colonias;
	
	int iteracao;

public:

    Jogo(int d);
    ~Jogo();

	int getDificuldade();



	void CriaSala(string sala);
	void AdicionaSala(Sala *s);
	void Move(char u[], char o[], char d[]);
	void turno();
	void DadosViagem();
	void TripulantesDisponiveis();
	vector<Evento*> getEventos();
	vector<Sala*> getSalas();
	void addEvento(Evento* e);
	void verificaEstadoSala(Sala *s);
	void mostraMensagens(string msg);
	bool VerificaSalas();
	string getNomeSala(int id) const;
	string getUnidades(int salai) const;
	int getOxigenio(int salai) const;
	int getIntegridade(int salai) const;
	void PrimeirosTripulantes();
	bool VerificaExisteSala(string nome_sala);
	bool VerificaExisteTripulantes(int pos);
	void gerirDano(int dano, string e); // terá que receber algo! 
	void setSalasAdjacentes(int sala, int s1, int s2, int s3, int s4);

	void gerirEvento();

private:
	bool chegouFim(int p);
	bool existeRaioLaser();
	bool operaPonte();
	bool operaRaioLaser();
	void provocaBrecha();

	int opcaoEvento();
	bool verificaExisteEvento(string e);
	int posEvento(string e);

	void danoChuvaMeteoritos(int dano);
	void danoAtaquePiratas(int dano);
	void danoAtaqueXenomorfo(int dano);
	void danoCampoCosmico(int dano);
	void invasaoPiratas();


};

#endif	/* MENU_H */

