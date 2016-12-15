#include "Caracteristica.h"

Caracteristica::Caracteristica(string n, int cm, int cf):nome(n), custo_monetario(cm),custo_forca(cf)
{
}

Caracteristica::~Caracteristica()
{
}

int Caracteristica::getCustoMonetario()
{
	return custo_monetario;
}

int Caracteristica::getCustoForça()
{
	return custo_forca;
}

