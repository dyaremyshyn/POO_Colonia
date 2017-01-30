#include "Caracteristica.h"
#include "Ser.h"
#include "Jogo.h"

Caracteristica::Caracteristica(string n, int cm, int cf, int idCar):nome(n), custo_monetario(cm),custo_forca(cf),id(idCar)
{
}

Caracteristica::~Caracteristica()
{
}

string Caracteristica::getNome()
{
	return nome;
}

int Caracteristica::getCustoMonetario()
{
	return custo_monetario;
}

int Caracteristica::getCustoForça()
{
	return custo_forca;
}

int Caracteristica::getID()
{
	return id;
}

