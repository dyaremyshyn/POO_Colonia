#include "Ser.h"
#include "Walker.h"
#include "Bandeira.h"

Ser::Ser(string n="Pessoa", int nCar=2):nome(n)
{
	caracteristicas.resize(nCar);
	saude = 10;
	ataque = 2;
	defesa = 2;
	
	ganhaCaracteristas(new Walker("Walker",1,1));
	ganhaCaracteristas(new Bandeira("Bandeira", 1, 0));

	calcularCusto();
}

Ser::Ser(string n, int nCar=1, vector<Caracteristica*> c): nome(n)
{
	caracteristicas.resize(nCar);
	saude = 10;
	ataque = 2;
	defesa = 2;

	for(int i =0;i<c.size();i++)
		ganhaCaracteristas(c.at(i));

	calcularCusto();
}

Ser::~Ser()
{
}

string Ser::getNome()
{
	return nome;
}

void Ser::setSaude(int s)
{
	saude = s;
}

int Ser::getSaude()
{
	return saude;
}

void Ser::setDefesa(int d)
{
	defesa = d;
}

int Ser::getDefesa()
{
	return defesa;
}

void Ser::setAtaque(int a)
{
	ataque = a;
}

int Ser::getAtaque()
{
	return ataque;
}

void Ser::ganhaCaracteristas(Caracteristica *c)
{
	caracteristicas.push_back(c);
}

void Ser::calcularCusto()
{
	
	for (int i = 0; i < caracteristicas.size(); i++)
		custo += caracteristicas.at(i)->getCustoMonetario();

}
