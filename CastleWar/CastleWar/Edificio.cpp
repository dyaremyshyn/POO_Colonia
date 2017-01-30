#include "Edificio.h"

Edificio::Edificio(char n, char b, int c, int s, int d): nome(n),bandeira(b), custo(c), saude(s), defesa(d)
{
	eid++;
	nivel = 1;

}

Edificio::~Edificio()
{
}

char Edificio::getNome()
{
	return nome;
}

void Edificio::setNome(char n)
{
	nome = n;
}

char Edificio::getBandeira()
{
	return bandeira;
}

void Edificio::setBandeira(char b)
{
	bandeira = b;
}

int Edificio::getNivel()
{
	return nivel;
}

void Edificio::setNivel(int n)
{
	nivel = n;
}

int Edificio::getPos()
{
	return 0;
}

void Edificio::setPos(int p)
{
	pos = p;
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

int Edificio::getEID()
{
	return eid;
}

void Edificio::aumentaNivel()
{
	nivel++;
}
