#include "Jogo.h"

Jogo::Jogo(int d){
	iteracao = 0;
	
	dificuldade = d+1;
	colonias.resize(dificuldade);


	colonias.at(1) = new Colonia("MyColony");




	salas.at(1) = new Sala;
	salas.at(2) = new Sala;
	salas.at(3) = new Sala;
	salas.at(4) = new Sala_Maquinas;
	salas.at(5) = new Suporte_Vida;
	salas.at(6) = new Controlo_Escudo;
	salas.at(7) = new Ponte;
	salas.at(8) = new Propulsor;
	salas.at(9) = new Sala;
	salas.at(10) = new Sala;
	salas.at(11) = new Sala;
	PrimeirosTripulantes();
	setSalasAdjacentes(0,1,NULL, NULL, NULL);
	setSalasAdjacentes(1,0,2,4, NULL);
	setSalasAdjacentes(2,1,3,5, NULL);
	setSalasAdjacentes(3,2,6, NULL, NULL);
	setSalasAdjacentes(4,1,5,9, NULL);
	setSalasAdjacentes(5,2,4,6,10);
	setSalasAdjacentes(6,3,5,11,7);
	setSalasAdjacentes(7,6, NULL, NULL, NULL);
	setSalasAdjacentes(8,9, NULL, NULL, NULL);
	setSalasAdjacentes(9,8,4,10, NULL);
	setSalasAdjacentes(10,9,5,11, NULL);
	setSalasAdjacentes(11,10,6, NULL, NULL);
}

Jogo::~Jogo(){
	for (unsigned int i = 0; i < eventos.size(); i++)
		delete eventos[i];
}
void Jogo::setSalasAdjacentes(int sala, int s1, int s2, int s3, int s4)
{
	if (s1 != NULL)
		salas[sala]->getSalasAdjacentes().push_back(salas[s1]);
	if (s2 != NULL)
		salas[sala]->getSalasAdjacentes().push_back(salas[s1]);
	if (s3 != NULL)
		salas[sala]->getSalasAdjacentes().push_back(salas[s1]);
	if (s4 != NULL)
		salas[sala]->getSalasAdjacentes().push_back(salas[s1]);

}

int Jogo::getDificuldade()
{
	return dificuldade;
}



void Jogo::PrimeirosTripulantes()
{
	for (int i = 0; i < 3; i++)
	{
		Tripulante *t = new Tripulante;
		int pos = 4 + (rand() % (int)(7 - 4 + 1));
		salas[pos]->AdicionaUnidade(t);
	}
}

bool Jogo::VerificaExisteSala(string nome_sala)
{
	for (unsigned int i = 0; i < salas.size(); i++)
	{
		if (salas[i]->getnome() == nome_sala)
			return true;
	}
	return false;
}

bool Jogo::VerificaExisteTripulantes(int pos)
{
	if (salas[pos]->getTripulantes())
		return true;
	return false;
}
void Jogo::CriaSala(string sala) {
	if (sala == "pa") {
		Sala *pa = new Propulsor;
		AdicionaSala(pa);
	}
	if (sala == "b") {
		Sala *b = new Beliche;
		AdicionaSala(b);
	}
	if (sala == "rl") {
		Sala *rl = new Raio_Laser;
		AdicionaSala(rl);
	}
	if (sala == "ar") {
		Sala *ar = new Auto_Reparador;
		AdicionaSala(ar);
	}
	if (sala == "ss") {
		Sala *ss = new Sistema_Seguranca;
		AdicionaSala(ss);
	}
	if (sala == "e") {
		Sala *e = new Enfermaria;
		AdicionaSala(e);
	}
	if (sala == "sa") {
		Sala *sa = new Sala_Armas;
		AdicionaSala(sa);
	}
	if (sala == "ac") {
		Sala *ac = new Alojamento_Capitao;
		AdicionaSala(ac);
	}
	if (sala == "or") {
		Sala *ofr = new Oficina_Robotica;
		AdicionaSala(ofr);
	}
}

void Jogo::AdicionaSala(Sala *s)
{
	for (unsigned int i = 0; i < salas.size(); i++) {
		if (s->getnome()=="Alojamento_Capitao" && salas[i]->getnome() == "Alojamento_Capitao")          //So pode existir uma sala para alijar o capitao
		{
			cout << "Ja existe uma sala para alojar o capitao";
			break;
		}
		if (salas[i]->getnome() == "?")
		{          //Adiciona sala caso ainda haja espaço no vetor de salas que existe na nave
			delete salas[i];
			salas.at(i) = s;
			break;
		}
		if (salas[11]->getnome() != "?")
		{
			c.gotoxy(3, 35);
			cout << "AVISO!" << endl;
			c.gotoxy(3, 36);
			cout << "Nao pode adicionar mais salas.";
			getchar();
			break;
		}
	}
}
void Jogo::Move(char u[], char o[], char d[])
{
	/*int i = 0;
	string arr[4];
	stringstream ssin(cmd);
	while (ssin.good() && i < 4) {
		ssin >> arr[i];
		++i;
	}*/
	string un(u);
	string ori(o);
	string des(d);

		if (/*stoi(arr[1])*/stoi(ori) > 12 || /*stoi(arr[2])*/ stoi(des) > 12)
		{
			//c.gotoxy(6, 35);
			cout << "Salas invalidas!";
			return;
		}
		if (salas[/*stoi(arr[1])*/stoi(ori)-1]->VerificaExisteUnidade(/*arr[0]*/un) == true)
		{
			salas[/*stoi(arr[2])*/stoi(des)-1]->AdicionaUnidade(salas[/*stoi(arr[2])*/stoi(ori)-1]->RemoveUnidade(un));
		}
}
bool Jogo::chegouFim(int p) {
	if (p >= fim)
		return true;
	return false;
}
void Jogo::turno()   
{
	int propulsao=0;
	iteracao += 1;

	if (!chegouFim(percurso)) {
			//for (unsigned int i = 0; i < getSalas().size(); i++)
			//{
			//	/*if(getSalas()[i]->)*/
			//	if (tripulantes[i]->estouPonte(tripulantes[i]->getOndeEstou()) == true) //Algum tripulante está a operar a ponte, a nave pode progredir
			//	{
		for (unsigned int i = 0; i < salas.size(); i++) //Verificar quantos propulsores a nave tem, a potencia da nave para deslocar-se é diretamente proporcional aos propulsores instalados
		{
			if (salas[i]->getnome() == "Propulsor")
			{
				propulsao += salas[i]->getintegridade();
			}
			//				//if (salas[4]->getintegridade() == 100  /*salas[7]->getestado()==true*/) //Sala de maquinas, se estiver em bom estado, a nave anda

		}
		percurso += propulsao;

		//}
		///*else {
		//	c.gotoxy(65, 5);
		//	cout << "Chegou ao fim do percurso!" << endl;
		//}*/



		//for (unsigned int i = 0; i < salas.size(); i++) //Verificar se beliches da nave estao destruidos, caso positivo, chegou ao fim do jogo
		//{
		//	if (salas[i]->getnome() == "Beliche" && salas[i]->getintegridade() <= 0)
		//		fim_jogo = true;
		//}
	}
}

void Jogo::DadosViagem()
{
	c.gotoxy(120, 3);
	cout << "********* Iteraccao: " << iteracao << " *********" << endl;
	c.gotoxy(120, 5);
	cout << "Objetivo: " << fim << "km" << endl;
	c.gotoxy(120, 6);
	cout << "Percurreu: " << percurso << "km" << endl;
	c.gotoxy(120, 7);
	cout << "Faltam: " << fim - percurso << "km" << endl;
}
void Jogo::TripulantesDisponiveis()
{
	for (unsigned int i = 0; i < salas.size(); i++)
	{
		c.gotoxy(120, i+16);
		cout << salas[i]->getNomeUnidades();
	}
}
vector<Sala*> Jogo::getSalas() {
	return salas;
}
void Jogo::addEvento(Evento *e) {
	eventos.push_back(e);
}

vector<Evento*> Jogo::getEventos() {
	return eventos;
}
void Jogo::verificaEstadoSala(Sala * s) {

	if (s->getintegridade() <= 0) {
		fim_jogo = true; //pára o jogo e diz que a nave tem uma sala destruida
		
		mostraMensagens("Uma das salas sofreu dano grave!");
	}
}
void Jogo::mostraMensagens(string msg) {
	c.gotoxy(120, 15);
	cout << msg << endl;
}
bool Jogo::VerificaSalas()
{
	if (salas[11]->getnome() == "?")
		return true;
	else
		return false;
}
string Jogo::getNomeSala(int id) const
{
	return salas[id]->getnome();
}
string Jogo::getUnidades(int salai) const
{
	return salas[salai]->getNomeUnidades();
}
int Jogo::getOxigenio(int salai) const
{
	return salas[salai]->getOxigenio();
}
int Jogo::getIntegridade(int salai) const
{
	return salas[salai]->getintegridade();
}
void Jogo::gerirDano(int dano, string e) { //recebemos o maior dano que um determinado evento proporciona e gerimos 

	if (e == "ChuvaMeteoritos") { // para o caso da chuva de meteoritos o dano diminui
		danoChuvaMeteoritos(dano);
	}
	else if (e == "AtaquePiratas") {
		danoAtaquePiratas(dano);
	}
	else if (e == "AtaqueXenomorfo") {
		danoAtaqueXenomorfo(dano);
	}
	else if (e == "CampoCosmico") {
		danoCampoCosmico(dano);
	}
	
}
void Jogo::danoChuvaMeteoritos(int dano) {
	int d = 0;

	if (operaPonte()) 
		dano -= 2;
	d = dano + (rand() % (int)((dano * 2) - dano + 1));

	if (existeRaioLaser()) {
		if (operaRaioLaser()) {
			for (int i = 0; i < d; i++) {
				srand(time(NULL));
				int prob = 0 + (rand() % (int)(100 - 0 + 1)); // valores aleatório entre 3 e 5

				if (prob >= 50) { // o que acontece se alguém estiver a operar a sala Raio Laser ?!
					d -= 1;
				}
			}
		}
	}

	if (d > 0) {
		for (int j = 0; j < d; j++) {
			if(escudo > 0)
				escudo-=10;	
			else {
				int x = 0 + (rand() % (int)(11 - 0 + 1));
				salas[x]->recebeDano(10);
				salas[x]->setOxigenio(0);
				provocaBrecha();
			}
		}
	}

}

void Jogo::danoAtaquePiratas(int dano) {
	int dif = 0;
	int i = 0;

	if (escudo > dano)
		escudo -= dano;
	else {
		dif = dano - escudo;
		do {
			srand(time(NULL));
			i = 0 + (rand() % (int)(100 - 0 + 1)); // valores aleatório entre 3 e 5
		} while (i == 6);
		salas[i]->setIntegridade(salas[i]->getintegridade() - dif);
		if (existeRaioLaser()) {
			if (operaRaioLaser()) {
				cout << "Dispara contra os Piratas!";
			}
			else
				invasaoPiratas();
		}
		else 
			invasaoPiratas();
	}
}
void Jogo::invasaoPiratas() {
	srand(time(NULL));
	int x = 3 + (rand() % (int)(5 - 3 + 1)); // valores aleatório entre 3 e 5
	int s = 0 + (rand() % (int)(11 - 0 + 1));

	for (int i = 0; i < x; i++) {
		salas[s]->AdicionaUnidade(new Pirata);
	}
}

void Jogo::danoAtaqueXenomorfo(int dano) { }		// primeiro acabas as unidades!

void Jogo::danoCampoCosmico(int dano) {
	int x = 3 + (rand() % (int)(5 - 3 + 1)); // valores aleatório entre 3 e 5
	for (int i = 0; i < x; i++) {
		srand(time(NULL));
		int y = 0 + (rand() % (int)(11 - 0 + 1)); // valores aleatório entre 3 e 5
		salas[y]->recebeDano(10);
	}
}

bool Jogo::existeRaioLaser() {
	if (VerificaExisteSala("Raio Laser"))
		return true;
	return false;
}

bool Jogo::operaPonte() {
	if (VerificaExisteTripulantes(7))
		return true;
	return false;
}

bool Jogo::operaRaioLaser() {
	int pos = 0;
	for (unsigned int i = 0; i < salas.size(); i++) {
		if (salas[i]->getnome() == "Raio Laser")
			pos = i;
	}
	if (VerificaExisteTripulantes(pos))
		return true;
	return false;
}

void Jogo::provocaBrecha()
{
	// criar uma brecha na nave (parte grafica)
}


//Nesta função gerimos os eventos, e geriamos da seguinte forma:
	// 20% -> para não acontecer nada durante esse turno 
	//  5% -> para receber um ataque de xenomorfos
	// 10% -> para receber um ataque de piratas
void Jogo::gerirEvento() {

	int op = opcaoEvento();
	int i = 0;
	switch (op) {
	case 1:
		if (!verificaExisteEvento("AtaqueXenomorfo"))
			addEvento(new AtaqueXenomorfo("AtaqueXenomorfo"));
		i = posEvento(("AtaqueXenomorfo"));
		(getEventos()[i])->danificaNave(this);
		break;
	case 2:
		if (!verificaExisteEvento("AtaquePiratas"))
			addEvento(new AtaquePiratas("AtaquePiratas"));
		i = posEvento(("AtaquePiratas"));
		(getEventos()[i])->danificaNave(this);
		break;
	case 3:
		if (verificaExisteEvento("ChuvaMeteoritos"))
			addEvento(new ChuvaMeteoritos("ChuvaMeteoritos"));
		i = posEvento(("ChuvaMeteoritos"));
		(getEventos()[i])->danificaNave(this);
		break;
	case 4:
		if (!verificaExisteEvento("CampoCosmico"))
			addEvento(new CampoCosmico("CampoCosmico"));
		i = posEvento(("CampoCosmico"));
		(getEventos()[i])->danificaNave(this);
		break;
	case 5:
		break;
	default:
		break;
	}

}
int Jogo::opcaoEvento() {

	srand(time(NULL));
	int r = rand() % 100 + 0;
	int op = 0;

	if (r <= 5) // ataque de xenomorfos
		op = 1;
	else if (r > 5 && r <= 15) // ataque de piratas
		op = 2;
	else if (r > 15 && r <= 35) // chuva de meteoritos
		op = 3;
	else if (r > 35 && r <= 65) // campo de pó cósmico
		op = 4;
	else if (r > 65) // não faz nada naquele turno
		op = 5;

	return op;
}
bool Jogo::verificaExisteEvento(string e) {

	for (unsigned int i = 0; i < (getEventos()).size(); i++)
		if (e == (getEventos())[i]->getNome())
			return true;
	return false;
}
int Jogo::posEvento(string e) {
	for (int i = 0; i < getEventos().size(); i++) {
		if (getEventos()[i]->getNome() == e)
			return i;
	}
}
