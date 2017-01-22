#include "Perfil.h"

Perfil::Perfil(char n): nome(n){
	custo_forca = 10;
}

Perfil::~Perfil() {}

char Perfil::getNome()
{
	return nome;
}

void Perfil::addCar(Caracteristica * c)
{
	car.push_back(c);
}

void Perfil::removeCar(Caracteristica * c)
{
	for (int i = 0; i < car.size(); i++)
		if (car.at(i)->getNome() == c->getNome())
			car.erase(car.begin() + i);
			
}

void Perfil::reCarByID(int idCar)
{
	for (int i = 0; i < car.size(); i++) {
		if (car.at(i)->getID() == idCar) {
			car.erase(car.begin() + i);
		}
	}
}

int Perfil::getCustoForca()
{
	return custo_forca;
}

void Perfil::setCustoForca(int cf)
{
	custo_forca = cf;
}
