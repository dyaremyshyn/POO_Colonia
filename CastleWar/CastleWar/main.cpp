#include "Libraries.h" 
#include "Interacao.h"

using namespace std;

int main(int argc, char** argv) {


	//********************** INTERFACE **************************************
	Interacao control;
	//control.Entrada();
	control.Novo_Jogo();
	control.MostraAmbienteGrafico();
	control.Configurar_Nave();
	control.Jogar();

}