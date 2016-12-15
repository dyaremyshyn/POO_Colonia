#include "Edificio.h"

Edificio::Edificio(string n, int c): nome(n), custo(c)
{
}

Edificio::~Edificio()
{
}

string Edificio::getNome()
{
	return nome;
}

void Edificio::setNome(string n)
{
	nome = n;
}

int Edificio::getCusto()
{
	return custo;
}

void Edificio::setCusto(int c)
{
	custo = c;
}

int Edificio::getSaude()
{
	return saude;
}

void Edificio::setSaude(int s)
{
	saude = s;
}

int Edificio::getDefesa()
{
	return defesa;
}

void Edificio::setDefesa(int d)
{
	defesa = d;
}
