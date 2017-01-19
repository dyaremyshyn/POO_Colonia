#include "Ser.h"
#include "Walker.h"
#include "Bandeira.h"

Ser::Ser(string n="Ser", int nCar=2):nome(n) {
	caracteristicas.resize(nCar);
	saude = 10;
	forca = 10;
	velocidade = 1;
	ataque = 1;
	defesa = 1;
	
	ganhaCaracteristas(new Walker("Walker",1,1));
	ganhaCaracteristas(new Bandeira("Bandeira", 1, 0));

	calcularCusto();
}


Ser::~Ser(){}

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

void Ser::setVelocidade(int v)
{
	velocidade = v;

}

int Ser::getVelocidade()
{
	return velocidade;
}

void Ser::setForca(int f)
{
	forca = f;
}

int Ser::getForca()
{
	return forca;
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

void Ser::efeitoCaracteristicas()
{
	for (int i = 0; i < caracteristicas.size(); i++) {
		caracteristicas[i]->fazEfeito(pos, this);
	}

}

boolean Ser::foraCastelo()
{
	if (pos->getColonia() != bandeira)
		return true;

	return false;
}
