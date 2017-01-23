#include "Colonia.h"

Colonia::Colonia(char n, int m):nome(n), moedas(m){

	posInicial = 0;
	addEdificio(new Castelo("Castelo", 0, 50, 10));
}

Colonia::~Colonia()
{
}

vector<Edificio*> Colonia::getEdificios()
{
	return edificios;
}

vector<Ser*> Colonia::getSeres()
{
	return seres;
}

char Colonia::getNome()
{
	return nome;
}

void Colonia::fazAccao()
{
}

int Colonia::getTam()
{
	return tamanho;
}

void Colonia::setPosInicial(int x)
{
	posInicial = x;
}

int Colonia::getPosInicial()
{
	return posInicial;
}

void Colonia::setMoedas(int m)
{
	moedas = m;
}

int Colonia::getMoedas()
{
	return moedas;
}

void Colonia::addEdificio(Edificio * e)
{
	edificios.push_back(e);
}

void Colonia::removeEdificio(int id)
{
	for (int i = 0; i < edificios.size(); i++) {
		if (edificios.at(i)->getEID() == id)
			edificios.erase(edificios.begin() + i);
	}
}

void Colonia::addSer(Ser * s)
{
	seres.push_back(s);
}

int Colonia::saudeCastelo()
{
	for (int i = 0; i < edificios.size(); i++) {
		if (edificios.at(i)->getNome() == "Castelo") {
			return edificios.at(i)->getSaude();
		}
	}
}
