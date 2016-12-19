#include "Jogo.h"

Jogo::Jogo(){

	config = new Configuracoes("config.txt");
	iteracao = 0;
	
	mundo.resize(config->getTamanho()*config->getTamanho());

	colonias.resize(config->getDificuldade()+1);

	colonias.at(1) = new Colonia("MyColony", config->getMoedas());
	for (int i = 2; i < config->getDificuldade() + 1; i++)
		colonias.at(i) = new Colonia("Colonia" + i - 1, config->getMoedas());

	preencheMundo();

	addPrimeirosSeres();
	
	addPrimeirosEdificios();


}

Jogo::~Jogo(){
	
}

void Jogo::addPrimeirosSeres()
{
	int x = 0;
	for (int i = 0; i < colonias.size(); i++) {
		for (int j = 0; j < 5; j++) {
			do {
				x = colonias.at(i)->getPosInicial() + (rand() % (int)((colonias.at(i)->getPosInicial() + colonias.at(i)->getTam()) - colonias.at(i)->getPosInicial() + 1));
				if (!mundo.at(x)->verificaSer()) {
					mundo.at(x)->setSer(new Ser("Pessoa", 2));
				}
			} while (mundo.at(x)->verificaSer());
		}
	}
}

void Jogo::addPrimeirosEdificios()
{
	int x = 0;
	for (int i = 0; i < colonias.size(); i++) {
		do {
			x = colonias.at(i)->getPosInicial() + (rand() % (int)((colonias.at(i)->getPosInicial() + colonias.at(i)->getTam()) - colonias.at(i)->getPosInicial() + 1));
			if (!mundo.at(x)->verificaEdifico()) {
				mundo.at(x)->setEdificio(new Castelo("Castelo", 0));
			}
		} while (mundo.at(x)->verificaEdifico());
	}
}

int Jogo::escolhePosColonia(int col)
{
	int x = 0;
	do {
		x = 1 + (rand() % (int)(mundo.size()-1 - 1 + 1)); 
		if (((x + colonias.at(col)->getTam()) <= (mundo.size() - 1)) && (!mundo.at(x)->verificaColonia())) {
			colonias.at(col)->setPosInicial(x);
			return x;
		}
	} while ((x + colonias.at(col)->getTam()) > mundo.size() - 1);
}

void Jogo::preencheMundo()
{
	for (int i = 1; i < mundo.size(); i++) {
		for (int j = 1; j < colonias.at(j)->getTam(); j++) {
			mundo.at(escolhePosColonia(j))->setColonia(colonias.at(j));
		}
	}
}

vector<Posicao*> Jogo::getMundo()
{
	return mundo;
}

vector<Colonia*> Jogo::getColonias()
{
	return colonias;
}



/*void Jogo::Move(char u[], char o[], char d[])
{
	
	string un(u);
	string ori(o);
	string des(d);

		if (stoi(ori) > mundo.size() || stoi(des) > mundo.size())
		{
			//c.gotoxy(6, 35);
			cout << "Salas invalidas!";
			return;
		}
		if (mundo[stoi(ori)-1]->VerificaExisteSer(un) == true)
		{
			mundo[stoi(des)-1]->AdicionaSer(mundo[stoi(ori)-1]->RemoveSer(un));
		}
}

void Jogo::turno()   
{
	
	iteracao += 1;

	if (!chegouFim()) {
			
		for (unsigned int i = 0; i < mundo.size(); i++) 
		{
			
		}
		
	}
}
*/