#include "Ser.h"
#include "Walker.h"
#include "Bandeira.h"

Ser::Ser(char n, vector<Caracteristica*>c):nome(n), caracteristicas(c) {
	
	saude = 10;
	maxSaude = 10;
	forca = 10; 
	velocidade = 1;
	ataque = 1;
	defesa = 1;

	castelo = true;

	calcularCusto();
}


Ser::~Ser(){}

char Ser::getBandeira()
{
	return bandeira;
}

void Ser::setBandeira(char b)
{
	bandeira = b;
}

char Ser::getNome()
{
	return nome;
}

void Ser::setPos(int p)
{
	pos = p;
}

int Ser::getPos()
{
	return pos;
}

void Ser::setSaude(int s)
{
	saude = s;
}

int Ser::getSaude()
{
	return saude;
}

void Ser::setMaxSaude(int s)
{
	maxSaude = s;
}

int Ser::getMaxSaude()
{
	return maxSaude;
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

vector<Caracteristica*> Ser::getCaracteristicas()
{
	return caracteristicas;
}

void Ser::ganhaCaracteristas(Caracteristica *c)
{
	caracteristicas.push_back(c);
}

void Ser::calcularCusto()
{
	
	for (unsigned int i = 0; i < caracteristicas.size(); i++)
		custo += caracteristicas.at(i)->getCustoMonetario();

}

void Ser::mover()
{
	int pos = -1 + (rand() % 1); //random num entre -1 e 1 
	setPos(getPos() + pos);
}

void Ser::efeitoCaracteristicas(Jogo *jogo)
{
	for (unsigned int i = 0; i < caracteristicas.size(); i++) {
		caracteristicas[i]->fazEfeito(pos, this,jogo);
	}

}

boolean Ser::dentroCastelo()
{
	return castelo;
}

void Ser::setCastelo(bool c)
{
	castelo = c;
}
