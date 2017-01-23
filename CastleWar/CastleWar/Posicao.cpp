#include "Posicao.h"

Edificio* Posicao::getEdifico()
{
	return e;
}

void Posicao::setEdificio(Edificio * e)
{
	this->e = e;
}

Ser* Posicao::getSer()
{
	return s;;
}

void Posicao::setSer(Ser * s)
{
	this->s = s;
}

//char Posicao::getColonia()
//{
//	return c->getNome();
//}

//void Posicao::setColonia(Colonia * c)
//{
//	this->c = c;
//}

//bool Posicao::verificaColonia()
//{
//	if (c != NULL)
//		return true;
//	return false;
//}

bool Posicao::verificaEdifico()
{
	if (e != NULL)
		return true;
	return false;
}

bool Posicao::verificaSer()
{
	if (s != NULL)
		return true;
	return false;
}

Posicao::Posicao()
{
	e = nullptr;
	s = nullptr;
	//c = NULL;
}

Posicao::~Posicao()
{
}
