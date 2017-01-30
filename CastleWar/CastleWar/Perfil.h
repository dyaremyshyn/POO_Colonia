#pragma once
#ifndef PERFIL_H
#define	PERFIL_H
#include "Libraries.h"
//#include "Edificio.h"
//#include "Ser.h"
//#include "Colonia.h"
#include "Caracteristica.h"

class Edificio;
class Ser;
class Caracteristica;

class Perfil {
	char nome;
	vector <Caracteristica*> car;
	int custo_forca;
	int ataque;
	int defesa;
	int velocidade;

public:

	Perfil(char n);
	~Perfil();

	char getNome();
	void addCar(Caracteristica*c);
	void removeCar(Caracteristica*c);
	void reCarByID(int idCar);
	int getCustoForca();
	void setCustoForca(int cf);

	vector <Caracteristica*> getCaracteristicas();
};



#endif	/* PERFIL_H */