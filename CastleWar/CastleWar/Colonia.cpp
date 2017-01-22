#include "Colonia.h"

Colonia::Colonia(char n, int m):nome(n), moedas(m){}

Colonia::~Colonia()
{
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
