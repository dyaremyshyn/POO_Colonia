#include "Jogo.h"

Jogo::Jogo(string fConfig){

	loadFicheiro(fConfig);
	iteracao = 0;
	
	mundo.resize(config->getLin()*config->getCol());

	myColonia = new Colonia(char(ascii), config->getMoedas());
	opoColonia.resize(config->getOponentes());

	opoColonia.at(1) = new Colonia(char(ascii), config->getMoedas());
	for (int i = 2; i < config->getOponentes(); i++)
		opoColonia.at(i) = new Colonia(char(++ascii), config->getMoedas());

}

Jogo::Jogo() {
	iteracao = 0;
}

Jogo::~Jogo(){
	
}

void Jogo::ComecarAJogar() {

	preencheMundo();

	addPrimeirosSeres();

	addPrimeirosEdificios();
}

void Jogo::loadFicheiro(string f) {
	config = new Configuracoes("config.txt"); //substituir por fConfig

	mundo.resize(config->getLin()*config->getCol());

	myColonia = new Colonia(char(ascii), config->getMoedas());
	opoColonia.resize(config->getOponentes());

	opoColonia.at(1) = new Colonia(char(ascii), config->getMoedas());
	for (int i = 2; i < config->getOponentes(); i++)
		opoColonia.at(i) = new Colonia(char(++ascii), config->getMoedas());
}

void Jogo::addPerfil(Perfil * p)
{
	perfil.push_back(p);
}

void Jogo::addCarAoPerfil(char p, int idCar)
{
	for (int i = 0; i < perfil.size(); i++) {
		if (perfil.at(i)->getNome() == p) {

			switch (idCar) {
			case 1:
				perfil.at(i)->addCar(new Bandeira("Bandeira",1,0, idCar));
				perfil.at(i)->setCustoForca(perfil.at(i)->getCustoForca() - 0);
				break;
			case 2:
				if (perfil.at(i)->getCustoForca() > 1) {
					perfil.at(i)->addCar(new Superior("Superior", 1, 1, idCar));
					perfil.at(i)->setCustoForca(perfil.at(i)->getCustoForca() - 1);
				}
				break;
			case 3:
				if (perfil.at(i)->getCustoForca() > 2) {
					perfil.at(i)->addCar(new PeleDura("Pele Dura", 2, 2, idCar));
					perfil.at(i)->setCustoForca(perfil.at(i)->getCustoForca() - 2);
				}
				break;
			case 4:
				if (perfil.at(i)->getCustoForca() > 3) {
					perfil.at(i)->addCar(new Armadura("Armadura", 2, 3, idCar));
					perfil.at(i)->setCustoForca(perfil.at(i)->getCustoForca() - 3);
				}
				break;
			case 5:
				if (perfil.at(i)->getCustoForca() > 1) {
					perfil.at(i)->addCar(new Faca("Faca", 1, 1, idCar));
					perfil.at(i)->setCustoForca(perfil.at(i)->getCustoForca() - 1);
				}
				break;
			case 6:
				if (perfil.at(i)->getCustoForca() > 2) {
					perfil.at(i)->addCar(new Espada("Espada", 2, 2, idCar));
					perfil.at(i)->setCustoForca(perfil.at(i)->getCustoForca() - 2);
				}
				break;
			case 7:
				if (perfil.at(i)->getCustoForca() > 1) {
					perfil.at(i)->addCar(new Agressao("Agressao", 1, 1, idCar));
					perfil.at(i)->setCustoForca(perfil.at(i)->getCustoForca() - 1);
				}
				break;
			case 8:
				if (perfil.at(i)->getCustoForca() > 1) {
					perfil.at(i)->addCar(new Ecologico("Ecologico", 1, 1, idCar));
					perfil.at(i)->setCustoForca(perfil.at(i)->getCustoForca() - 1);
				}
				break;
			case 9:
				if (perfil.at(i)->getCustoForca() > 1) {
					perfil.at(i)->addCar(new HeatSeeker("Heat Seeker", 1, 1, idCar));
					perfil.at(i)->setCustoForca(perfil.at(i)->getCustoForca() - 1);
				}
				break;
			case 10:
				if (perfil.at(i)->getCustoForca() > 1) {
					perfil.at(i)->addCar(new BuildSeeker("Build Seeker", 1, 1, idCar));
					perfil.at(i)->setCustoForca(perfil.at(i)->getCustoForca() - 1);
				}
				break;
			case 11:
				if (perfil.at(i)->getCustoForca() > 1) {
					perfil.at(i)->addCar(new Walker("Walker", 1, 1, idCar));
					perfil.at(i)->setCustoForca(perfil.at(i)->getCustoForca() - 1);
				}
				break;
			case 12:
				if (perfil.at(i)->getCustoForca() > 1) {
					perfil.at(i)->addCar(new Remedio("Remedio", 2, 1, idCar));
					perfil.at(i)->setCustoForca(perfil.at(i)->getCustoForca() - 1);
				}
				break;
			case 13:
				if (perfil.at(i)->getCustoForca() > 0) {
					perfil.at(i)->addCar(new SecondChance("Second Chance", 3, 0, idCar));
					perfil.at(i)->setCustoForca(perfil.at(i)->getCustoForca() - 0);
				}
				break;
			}
		}

		

	}
}

void Jogo::removeCarAoPerfil(char p, int idCar) {
	for (int i = 0; i < perfil.size(); i++) {
		if (perfil.at(i)->getNome() == p) {
			perfil.at(i)->reCarByID(idCar);
		}
	}
}

void Jogo::removePerfil(char p)
{
	for (int i = 0; i < perfil.size(); i++) {
		if (perfil.at(i)->getNome() == p)
			perfil.erase(perfil.begin() + i);
	}
}

void Jogo::addPrimeirosSeres()
{
	int x = 0;
	for (int i = 0; i < opoColonia.size(); i++) {
		for (int j = 0; j < 5; j++) {
			do {
				x = opoColonia.at(i)->getPosInicial() + (rand() % (int)((opoColonia.at(i)->getPosInicial() + opoColonia.at(i)->getTam()) - opoColonia.at(i)->getPosInicial() + 1));
				if (!mundo.at(x)->verificaSer()) {
					mundo.at(x)->setSer(new Ser("Ser"));
				}
			} while (mundo.at(x)->verificaSer());
		}
	}
}

void Jogo::addPrimeirosEdificios()
{
	int x = 0;
	for (;;) //falta implementar a parte da myColonia!!!! 

	for (int i = 0; i < opoColonia.size(); i++) {
		do {
			x = opoColonia.at(i)->getPosInicial() + (rand() % (int)((opoColonia.at(i)->getPosInicial() + opoColonia.at(i)->getTam()) - opoColonia.at(i)->getPosInicial() + 1));
			if (!mundo.at(x)->verificaEdifico()) {
				mundo.at(x)->setEdificio(new Castelo("Castelo", 0,50,10));
			}
		} while (mundo.at(x)->verificaEdifico());
	}
}

int Jogo::escolhePosColonia(int col)
{
	int x = 0;
	do {
		x = 1 + (rand() % (int)(mundo.size()-1 - 1 + 1)); 
		if (((x + opoColonia.at(col)->getTam()) <= (mundo.size() - 1)) && (!mundo.at(x)->verificaColonia())) {
			opoColonia.at(col)->setPosInicial(x);
			return x;
		}
	} while ((x + opoColonia.at(col)->getTam()) > mundo.size() - 1);
}

void Jogo::preencheMundo()
{


	for (int i = 1; i < mundo.size(); i++) {
		for (int j = 1; j < opoColonia.at(j)->getTam(); j++) {
			mundo.at(escolhePosColonia(j))->setColonia(opoColonia.at(j));
		}
	}
}

Colonia* Jogo::getMyColonia()
{
	return myColonia;
}



vector<Posicao*> Jogo::getMundo()
{
	return mundo;
}

vector<Colonia*> Jogo::getOpoColonias()
{
	return opoColonia;
}

void Jogo::criaMundo(int dim)
{
	mundo.resize(dim);
}

void Jogo::criaMyColonia(int m)
{
	myColonia = new Colonia(char(ascii), m);
}

void Jogo::criaColOponentes(int m, int o)
{
	opoColonia.resize(o);
	for (int i = 2; i < o; i++)
		opoColonia.at(i) = new Colonia(char(++ascii), m);
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