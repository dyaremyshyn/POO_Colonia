//
//  configuracoes.cpp
//  teste2
//
//  Created by João Pedro Janeiro on 14/12/16.
//  Copyright © 2016 João Pedro Janeiro. All rights reserved.
//

#include "Configuracoes.h"

#include "Libraries.h"


Configuracoes::Configuracoes(string nf="config.txt"): nome_ficheiro(nf) {

	cout << leFicheiro(nome_ficheiro) << endl;

	getAsString();

}

Configuracoes::~Configuracoes()
{
}

int Configuracoes::getDificuldade()
{
	return dificuldade;
}

int Configuracoes::getTamanho()
{
	return t;
}

int Configuracoes::getFoco()
{
	return f;
}

int Configuracoes::getMoedas()
{
	return moedas;
}


bool Configuracoes::leFicheiro(string nome_ficheiro) {

	ifstream dados(nome_ficheiro);
	string linha;
	
	if (!dados.is_open()) {
		return false;
	}
	while (!dados.eof())
	{
		
		getline(dados, linha);
		istringstream iss(linha);
		iss >> this->dificuldade >> t >> moedas;

		return true;

	}

	return false;
};

void Configuracoes::getAsString()const {

	cout << "dificuldade:" << this->dificuldade << " tamanho:" << this->t  << " moedas:" << this->moedas << endl;

};
