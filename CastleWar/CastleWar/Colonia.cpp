#include "Colonia.h"

Colonia::Colonia(string n, int m):nome(n), moedas(m){}

Colonia::~Colonia()
{
}

string Colonia::getNome()
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
