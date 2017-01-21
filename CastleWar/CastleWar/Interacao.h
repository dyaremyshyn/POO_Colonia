#pragma once

#include "Jogo.h"


class Interacao {
	
public:
	Interacao();
	void Entrada(); //Fun��o s� para ficar com um aspeto grafico inicial mais bonito
	void Configurar_Jogo(); //Fun��o para ler comandos inseridos pelo utilizador
	void MostraAmbienteGrafico(); //Mostrar nave
	void next() { }
	void Novo_Jogo();
	//void Jogar();
	
	void Jogo_A_Iniciar();

	
	//int escreveIntegridade(int pos);
private:
	bool configuracao = false;
	Jogo *jogo;//Ponteiro para poder aceder a classe jogo
	bool jogo_criado;
	//void limpaParteDireita();
	void loadPorFich();
	void criarJogo();
};

