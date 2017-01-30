#include "Jogo.h"
#include "Edificio.h"
#include "Quinta.h"
#include "Torre.h"


Jogo::Jogo(string fConfig){

	loadFicheiro(fConfig);
	iteracao = 0;
	
	mundo.resize(config->getLin()*config->getCol());

	myColonia = new Colonia(ascii, config->getMoedas());
	opoColonia.resize(config->getOponentes());


	for (int i = 0; i < config->getOponentes(); i++)
		opoColonia.at(i) = new Colonia(++ascii, config->getMoedas());

}

Jogo::Jogo() {
	myColonia = NULL;
	iteracao = 0;
	ascii = 'a';
}

Jogo::~Jogo(){
	
}

vector<Perfil*> Jogo::getPerfil()
{
	return perfil;
}

void Jogo::mostraCarDePerfil(char c)
{
	int linha = 2;
	string car = "";
	Consola::gotoxy(193, linha);
	cout << "Caracteristicas de perfil "<<c<<":";
	for (unsigned int i = 0; i < perfil.size(); i++) {
		if (perfil.at(i)->getNome() == c) {
			for (unsigned int j = 0; j < perfil.at(i)->getCaracteristicas().size(); j++)
				car += perfil.at(i)->getCaracteristicas().at(j)->getID() + " ";
		}

	}
	linha = linha + 2;
	Consola::gotoxy(155, linha);
	cout << "idCar: " << car;

}

void Jogo::mkBuild(char e, int l, int c, char col)
{
	if (col == 'a') {
		buildEdif(e, l*c, getMyColonia());
	}
	else {
		for (unsigned int i = 0; i < opoColonia.size(); i++) {
			if(opoColonia.at(i)->getNome()==col)
				buildEdif(e, l*c, opoColonia.at(i));
		}
	}
}

void Jogo::repairBuild(int id)
{
	for (unsigned int i = 0; i < myColonia->getEdificios().size(); i++) {
		if (myColonia->getEdificios().at(i)->getEID() == id) {
			myColonia->getEdificios().at(i)->setSaude(myColonia->getEdificios().at(i)->getSaude() + 1);
		}
	}
}

void Jogo::upgradeBuild(int id)
{
	for (unsigned int i = 0; i < myColonia->getEdificios().size(); i++) {
		if (myColonia->getEdificios().at(i)->getEID() == id) {
			myColonia->getEdificios().at(i)->upgrade();
			myColonia->setMoedas(myColonia->getMoedas() - 10);
		}
	}
}

void Jogo::sellBuild(int id)
{
	for (unsigned int i = 0; i < myColonia->getEdificios().size(); i++) {
		if (myColonia->getEdificios().at(i)->getEID() == id) {
			myColonia->setMoedas(myColonia->getMoedas() + myColonia->getEdificios().at(i)->getCusto());
			myColonia->removeEdificio(id);
		}
	}
}

void Jogo::criaSer(int n, char p)
{
	Perfil *perf=NULL;
	for (unsigned int i = 0; i < perfil.size(); i++)
		if (perfil.at(i)->getNome() == p)
			perf = perfil.at(i);

	for (unsigned int i = 0; i < n; i++) {
		Ser *s = new Ser('s', perf->getCaracteristicas());
		s->setPos(myColonia->getPosInicial());
		myColonia->addSer(s);
	}
}

void Jogo::ataca()
{
	for (unsigned int i = 0; i < myColonia->getSeres().size(); i++) {
		myColonia->getSeres().at(i)->mover();
		myColonia->getSeres().at(i)->efeitoCaracteristicas(this);
	}
}

void Jogo::recolhe()
{
	for (unsigned int i = 0; i < myColonia->getSeres().size(); i++) {
		if (myColonia->getSeres().at(i)->getPos() < myColonia->getPosInicial())
			myColonia->getSeres().at(i)->setPos(myColonia->getSeres().at(i)->getPos() + 1);
		else if (myColonia->getSeres().at(i)->getPos() > myColonia->getPosInicial()) {
			myColonia->getSeres().at(i)->setPos(myColonia->getSeres().at(i)->getPos() - 1);
		}
	}
}

bool Jogo::lerComandosFicheiro(string fich)
{
	int n;

	ifstream dados(fich);
	string linha;
	string comando;
	
	if (!dados.is_open()) {
		return false;
	}
	getline(dados, linha);
	n = stoi(linha);
	comandosFicheiro.resize(n);  //esta mal
	while (!dados.eof())
	{
		
		getline(dados, linha);
		istringstream iss(linha);
		iss >> comando;

		comandosFicheiro.push_back(comando);
		return true;

	}

	return false;
}



void Jogo::loadFicheiro(string f) {
	config = new Configuracoes("config.txt"); //substituir por f

	mundo.resize(config->getLin()*config->getCol()); //esta mal, nao usar resize

	myColonia = new Colonia(ascii, config->getMoedas());
	opoColonia.resize(config->getOponentes()); //esta mal, nao usar resize

	for (int i = 0; i < config->getOponentes(); i++)
		opoColonia.at(i) = new Colonia(++ascii, config->getMoedas());
}

void Jogo::addPerfil(Perfil * p)
{
	perfil.push_back(p);
}

void Jogo::addCarAoPerfil(char p, int idCar)
{
	for (unsigned int i = 0; i < perfil.size(); i++) {
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
	for (unsigned int i = 0; i < perfil.size(); i++) {
		if (perfil.at(i)->getNome() == p) {
			perfil.at(i)->reCarByID(idCar);
		}
	}
}

void Jogo::removePerfil(char p)
{
	for (unsigned int i = 0; i < perfil.size(); i++) {
		if (perfil.at(i)->getNome() == p)
			perfil.erase(perfil.begin() + i);
	}
}

//void Jogo::addPrimeirosSeres()
//{
//	int x = 0;
//	for (int i = 0; i < opoColonia.size(); i++) {
//		for (int j = 0; j < 5; j++) {
//			do {
//				x = opoColonia.at(i)->getPosInicial() + (rand() % (int)((opoColonia.at(i)->getPosInicial() + opoColonia.at(i)->getTam()) - opoColonia.at(i)->getPosInicial() + 1));
//				if (!mundo.at(x)->verificaSer()) {
//					mundo.at(x)->setSer(new Ser("Ser"));
//				}
//			} while (mundo.at(x)->verificaSer());
//		}
//	}
//}

//void Jogo::addPrimeirosEdificios()
//{
//	int x = 0;
//	for (;;) //falta implementar a parte da myColonia!!!! 
//
//	for (unsigned int i = 0; i < opoColonia.size(); i++) {
//		do {
//			x = opoColonia.at(i)->getPosInicial() + (rand() % (int)((opoColonia.at(i)->getPosInicial() + opoColonia.at(i)->getTam()) - opoColonia.at(i)->getPosInicial() + 1));
//			if (!mundo.at(x)->verificaEdifico()) {
//				mundo.at(x)->setEdificio(new Castelo('C', 0,50,10));
//			}
//		} while (mundo.at(x)->verificaEdifico());
//	}
//}

//int Jogo::escolhePosColonia(int col)
//{
//	int x = 0;
//	do {
//		x = 1 + (rand() % (int)(mundo.size()-1 - 1 + 1)); 
//		if (((x + opoColonia.at(col)->getTam()) <= (mundo.size() - 1)) && (!mundo.at(x)->verificaColonia())) {
//			opoColonia.at(col)->setPosInicial(x);
//			return x;
//		}
//	} while ((x + opoColonia.at(col)->getTam()) > mundo.size() - 1);
//}

void Jogo::preencheMundo()
{
	for (unsigned int i = 0; i < mundo.size(); i++) {
		
		//PARA A MINHA COLONIA
		for (unsigned int j = 0; j < myColonia->getEdificios().size(); j++) {
			if (myColonia->getEdificios().at(j)->getPos() == i) {
				mundo.at(i)->setEdificio(myColonia->getEdificios().at(j));
			}	
		}
		for (unsigned int k = 0; k < myColonia->getSeres().size(); k++) {
			if (myColonia->getSeres().at(k)->getPos() == i)
				mundo.at(i)->setSer(myColonia->getSeres().at(k));
		}

		//PARA OS OPONENTES
		for (unsigned int j = 0; j < opoColonia.size(); j++) {
			for (unsigned int k = 0; k < opoColonia.at(j)->getEdificios().size(); k++) {
				if (opoColonia.at(j)->getEdificios().at(k)->getPos() == i)
					mundo.at(i)->setEdificio(opoColonia.at(i)->getEdificios().at(k));
			}
			for (unsigned int kk = 0; kk < opoColonia.at(j)->getSeres().size(); kk++) {
				if (opoColonia.at(j)->getSeres().at(kk)->getPos() == i)
					mundo.at(i)->setSer(opoColonia.at(i)->getSeres().at(kk));
			}
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

void Jogo::setMoedasNumaColonia(char c, int m)
{
	if (c == 'a')
		myColonia->setMoedas(m);
	else {
		for (unsigned int i = 0; i < opoColonia.size(); i++) {
			if (opoColonia.at(i)->getNome() == c)
				opoColonia.at(i)->setMoedas(m);
		}
	}

}

void Jogo::buildEdif(char nomeEdif, int pos, Colonia *c)
{
	
	int inicio = c->getPosInicial() - 10;
	int fim = c->getPosInicial() + 10;

	if (inicio < pos && pos < fim) {
		if (mundo.at(pos)->verificaEdifico() == false) {
			Edificio *e=nullptr;
			if (nomeEdif ==  'Q') {
				e = new Quinta(nomeEdif,c->getNome(), 20, 20, 10);
			}
			else if (nomeEdif == 'T') {
				e = new Torre(nomeEdif, c->getNome(), 30, 20, 10);
			}
			e->setPos(pos);
			c->addEdificio(e);
			mundo.at(pos)->setEdificio(e);
			c->setMoedas(c->getMoedas() - e->getCusto());
		}
	}
}

void Jogo::listaColonia(char c)
{
	int linha = 2;
	string car;
	Consola::gotoxy(193, linha);
	cout << "Edificios: ";
	if (c == 'a') {
		for (unsigned int i = 0; i < myColonia->getEdificios().size(); i++) {
			linha = linha + 2;
			Consola::gotoxy(155, linha);
			cout << "Pos: "<< myColonia->getEdificios().at(i)->getPos()<<" Saude: "<< myColonia->getEdificios().at(i)->getSaude()<<" Def: "<< myColonia->getEdificios().at(i)->getDefesa();
		}
		for (unsigned int i = 0; i < myColonia->getSeres().size(); i++) {
			linha = linha + 2;
			Consola::gotoxy(155, linha);
			cout << "Ataq: " << myColonia->getSeres().at(i)->getAtaque() << " Def: " << myColonia->getSeres().at(i)->getDefesa() << "Saude: " << myColonia->getSeres().at(i)->getSaude();
			linha++;
			for (unsigned int j = 0; j < myColonia->getSeres().at(i)->getCaracteristicas().size(); j++) {
				car += myColonia->getSeres().at(i)->getCaracteristicas().at(j)->getID() + " ";
			}
			Consola::gotoxy(155, linha);
			cout << "IDCar: " << car;
		}
	}
	else {
		for (unsigned int i = 0; i < opoColonia.size(); i++) {
			if (c == opoColonia.at(i)->getNome()) {
				for (unsigned int i = 0; i < myColonia->getEdificios().size(); i++) {
					linha = linha + 2;
					Consola::gotoxy(155, linha);
					cout << "Pos: " << myColonia->getEdificios().at(i)->getPos() << " Saude: " << myColonia->getEdificios().at(i)->getSaude() << " Def: " << myColonia->getEdificios().at(i)->getDefesa();
				}
				for (unsigned int i = 0; i < myColonia->getSeres().size(); i++) {
					linha = linha + 2;
					Consola::gotoxy(155, linha);
					cout << "Ataq: " << myColonia->getSeres().at(i)->getAtaque() << " Def: " << myColonia->getSeres().at(i)->getDefesa() << "Saude: " << myColonia->getSeres().at(i)->getSaude();
					linha++;
					for (unsigned int j = 0; j < myColonia->getSeres().at(i)->getCaracteristicas().size(); j++) {
						car += myColonia->getSeres().at(i)->getCaracteristicas().at(j)->getID() + " ";
					}
					Consola::gotoxy(155, linha);
					cout << "IDCar: " << car;
				}
			}
		}
	}
}


void Jogo::criaMundo(int dim)
{
	for (unsigned int i = 0; i < dim; i++)
		mundo.push_back(new Posicao());
}

void Jogo::criaMyColonia(int m)
{
	myColonia = new Colonia(ascii, m);
}

void Jogo::criaColOponentes(int m, int o)
{
	for (int i = 0; i < o; i++)
		opoColonia.push_back( new Colonia(++ascii, m));
}



void Jogo::turno()   
{
	iteracao += 1;

	if (myColonia->saudeCastelo()>0) {
		for (unsigned int i = 0; i < myColonia->getEdificios().size(); i++) {
			myColonia->getEdificios().at(i)->fazEfeito(this);
		}
		for (unsigned int j = 0; j < myColonia->getSeres().size(); j++) {
			myColonia->getSeres().at(j)->efeitoCaracteristicas(this);
		}

		removeMortos();

		//funcao para mostrar saude do castelo, moedas 
		preencheMundo();
	}
}

void Jogo::removeMortos()
{
	for (unsigned int i = 0; i < myColonia->getEdificios().size(); i++) {
		if (myColonia->getEdificios().at(i)->getSaude() <= 0) {
			delete myColonia->getEdificios().at(i);
			myColonia->getEdificios().erase(myColonia->getEdificios().begin() + i);
		}
	}
	for (unsigned int i = 0; i < myColonia->getSeres().size(); i++) {
		delete myColonia->getSeres().at(i);
		myColonia->getSeres().erase(myColonia->getSeres().begin() + i);
	}
}
