#pragma once

#include "Jogo.h"


class Interacao {
	
public:
	Interacao();
	void Entrada(); //Função só para ficar com um aspeto grafico inicial mais bonito
	void Configurar_Jogo(); //Função para ler comandos inseridos pelo utilizador
	void MostraAmbienteGrafico(); //Mostrar 
	void next() { }
	void Novo_Jogo();
	void Jogar();
	
	void Jogo_A_Iniciar();
	void MostraMundo();

	void setFoco(int f);
	int getFoco();
private:
	int foco;
	bool configuracao = false;
	Jogo *jogo;//Ponteiro para poder aceder a classe jogo
	bool jogo_criado;
	void limpaParteDireita();
	void loadPorFich();
	void criarJogo();
	void ComandosJogo();
};

