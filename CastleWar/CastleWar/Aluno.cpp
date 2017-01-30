#include "Aluno.h"
#include "Ser.h"
#include "Jogo.h"

Aluno::Aluno(string n, int cm, int cf,int idCar) : Caracteristica(n, cm, cf, idCar)
{
}

Aluno::~Aluno()
{
}

void Aluno::fazEfeito(int p, Ser * s, Jogo *jogo)
{
}
