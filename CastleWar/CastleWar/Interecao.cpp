#include "Interacao.h"
#include "Jogo.h"
class Evento;

Interacao::Interacao()
{
		jogo_criado = false; //O jogador ainda nao iniciou o jogo
}
void Interacao::Entrada()
{
	Consola::setTextSize(8, 8); //Temos de diminuir o tamanho da letra para caber dentro da janela
	Consola::setScreenSize(100, 300);  //Valores muito altos podem nao dar
	Consola::setBackgroundColor(Consola::PRETO);  //Utilizar o c.Preto para aceder a constante para o Preto
	Consola::setTextColor(Consola::BRANCO_CLARO);
	Consola::clrscr();
	
	Consola::setTextSize(14, 14);
	Consola::setTextColor(Consola::VERMELHO_CLARO);
	cout << "\n****************   OOOOOOOOOOOO))  O))                  O))    ****************  \n";
	cout << "****************   O))                O))                O))    ****************  \n";
	cout << "****************   O))                 O))              O))     ****************  \n";
	cout << "****************   O))                  O))     O      O))      ****************  \n";
	cout << "****************   O))                   O))   OOO    O))       ****************  \n";
	cout << "****************   O))                    O))  O O   O))        ****************  \n";
	cout << "****************   O OOOOOOOOOOOO))        OOOO  OOOO           ****************  \n";
	Consola::gotoxy(35, 92);
	Consola::setTextColor(Consola::AMARELO_CLARO);
	cout << "<<INSERT COIN!>>\n";
	getchar();
	Consola::clrscr();
	Consola::setTextColor(Consola::BRANCO_CLARO);
	Consola::setBackgroundColor(Consola::PRETO);  // favor consultar o .h para ver as constantes
	Consola::setTextColor(Consola::BRANCO_CLARO);
	Consola::setScreenSize(100, 300);
}
void Interacao::Novo_Jogo()
{
	string n;

	regex regex_pattern("^[1-9]+$");
	do
	{
		
		Consola::clrscr_comandline();
		Consola::gotoxy(3, 35);
		cout << "1 - Carregar config do ficheiro";
		Consola::gotoxy(3, 36);
		cout << "2 - Configurar jogo manualmente";
		Consola::gotoxy(3, 37);
		cin >> n;
	} while (!regex_match(n, regex_pattern));

	int valor = atoi(n.c_str()); //converter string n para inteiro

	switch (valor)
	{
	case 1:
		loadPorFich();
		break;
	case 2:
		criarJogo();
		break;
	default:
		break;
	}

	
}


void Interacao::loadPorFich() {
	string n;
	ifstream myReadFile;

	regex regex_pattern("^[1-9]+$");
	do
	{
		Consola::gotoxy(3, 38);
		Consola::clrscr_comandline();
		do {
			cout << "Introduza o nome do ficheiro: ";
			cin >> n;
			myReadFile.open(n);
		}while (!regex_match(n, regex_pattern));
	} while (!myReadFile.is_open());
	jogo = new Jogo(n);
}

void Interacao::criarJogo() {
	string n;

	MostraAmbienteGrafico();
	
	
	
}

void Interacao::MostraAmbienteGrafico()
{
	Consola::setScreenSize(100, 300);
	Consola::setTextSize(14, 14);
	Consola::clrscr();
	/*Desenhar janela esquerda onde vai estar o mundo*/
	Consola::gotoxy(1, 1);
	
	for (int i = 0; i < 180; i++) //Desenhar linha horizontal superior da janela  115
		cout << char(220);

	Consola::gotoxy(1, 49); //estava 30
	for (int i = 0; i < 180; i++) //Desenhar linha horizontal inferior da janela
		cout << char(220);

	for (int j = 2; j < 50; j++) //Desenhar linha vertical esquerda da janela  (estava 31)
		{
			Consola::gotoxy(1, j);
			cout << char(178);
		}

	for (int j = 2; j < 50; j++) //Desenhar linha vertical direita da janela
	{
		Consola::gotoxy(150, j);
		cout << char(178);
	}


	/*Desenhar janela direita onde vai estar o historico de eventos*/
	Consola::gotoxy(181, 1);
	for (int i = 0; i < 52; i++) //Desenhar linha horizontal superior da janela
		cout << char(220);

	Consola::gotoxy(181, 49);
	for (int i = 0; i < 52; i++) //Desenhar linha horizontal inferior da janela
		cout << char(220);

	for (int j = 2; j < 50; j++) //Desenhar linha vertical esquerda da janela
	{
		Consola::gotoxy(152, j);
		cout << char(178);
	}

	for (int j = 2; j < 50; j++) //Desenhar linha vertical direita da janela
	{
		Consola::gotoxy(233, j);
		cout << char(178);
	}

	/*Desenhar janela direita onde vai estar a linha de comandos*/
	Consola::gotoxy(1, 50);
	for (int i = 0; i < 233; i++) //Desenhar linha horizontal superior da janela
		cout << char(220);

	Consola::gotoxy(1, 55);
	for (int i = 0; i < 233; i++) //Desenhar linha horizontal inferior da janela
		cout << char(220);

	for (int j = 50; j < 56; j++) //Desenhar linha vertical esquerda da janela
	{
		Consola::gotoxy(1, j);
		cout << char(178);
	}

	for (int j = 50; j < 56; j++) //Desenhar linha vertical direita da janela
	{
		Consola::gotoxy(233, j);
		cout << char(178);
	}

	/*////////////////////////////////DESENHAR PLANICIE/////////////////////////////////////////*/
	
	for (int j = 3; j < 46; j =j+8) {
		Consola::gotoxy(5, j);
		for (int i = 0; i < 115; i++)		//Linhas da planicie
			cout << char(178);
		
	}

	for (int i = 5; i < 140; i = i + 23) //Ciclo para desenhar colunas da segunda linha da nave
	{
		for (int j = 3; j < 44; j++) //Cada espaçamente entre as linhas tem 8 caracteres
		{
			Consola::gotoxy(i, j);
			cout << char(178);
		}
	}
	
	Consola::gotoxy(5,45);
	cout << "Foco: 5 x 5 estatico";
	if(jogo_criado==false){
		Jogo_A_Iniciar();
	}
	

	Consola::gotoxy(75, 50);
	cout << "<<Comandos>>";
	Consola::gotoxy(3, 52);
	cout << ">>:";
	
	
	/*********************************************Desenhar castelos/seres****************************************/
	
	/*****************************************Acabou de Desenhar Salas**************************************/
	

}
void Interacao::Jogo_A_Iniciar()
{

	/*************************************Mostrar comandos disponiveis********************************/
	Consola::gotoxy(190, 2);
	cout << "Configurar Jogo: ";
	Consola::gotoxy(155, 4);
	cout << "Comandos: ";
	Consola::gotoxy(155, 6);
	cout << "dim lin col -> Dim da planicie";
	Consola::gotoxy(155, 8);
	cout << "moedas num -> Numero de moedas";
	Consola::gotoxy(155, 10);
	cout << "oponentes num -> Numero de oponentes";
	Consola::gotoxy(155, 12);
	cout << "castelo colonia lin col -> Posiciona o castelo numa posicao indicada";
	Consola::gotoxy(155, 14);
	cout << "mkperfil letra -> Cria um perfil";
	Consola::gotoxy(155, 16);
	cout << "addperfil letra car -> Add uma caracteristica ao perfil indicado";
	Consola::gotoxy(155, 18);
	cout << "subperfil letra car -> Remove uma caracteristica ao perfil indicado";
	Consola::gotoxy(155, 20);
	cout << "rmperfil letra -> Remove o perfil indicado";
	Consola::gotoxy(155, 22);
	cout << "load ficheiro -> Carrega config de um ficheiro";
	Consola::gotoxy(155, 24);
	cout << "inicio -> Comecar a jogar";

}
/*
void Interacao::Configurar_Jogo() {

	while (1) {
		Consola::gotoxy(6, 35);
		string comando, cmd;
		Consola::clrscr_comandline();
		getline(cin, comando);

		
	}
}
*/
void Interacao::Configurar_Jogo() {
	//regex regex_pattern("\s");
	
	while (1) {
		
		Consola::gotoxy(6, 35);
		string comando, cmd;
		Consola::clrscr_comandline();
		getline(cin, comando);

		if (cmd == "next") // passar para próxima iteracção
			next();
		else {
			istringstream iss(comando);
			iss >> cmd;

			//******************************* Comandos Relativos a Configuração do Jogo ************************************
			if (cmd == "mover") { //regex_match(cmd, regex_pattern
				char o[2];
				char d[2];
				char u[2];
				Consola::clrscr_comandline();
				Consola::gotoxy(5, 35);
				cout << "Unidade: ";
				cin >> u; 
				Consola::clrscr_comandline();
				Consola::gotoxy(5, 35);
				cout << "Origem: ";
				cin >> o;
				Consola::clrscr_comandline();
				Consola::gotoxy(5, 35);
				cout << "Destino: ";
				cin >> d;
				jogo->Move(u,o,d);
				MostraAmbienteGrafico();
			}
			if (cmd == "pa") {
				jogo->CriaSala("pa");
				MostraAmbienteGrafico();
			}
			if (cmd == "b") {
				jogo->CriaSala("b");
				MostraAmbienteGrafico();
			}
			if (cmd == "rl") {
				jogo->CriaSala("rl");
				MostraAmbienteGrafico();
			}
			if (cmd == "ar") {
				jogo->CriaSala("ar");
				MostraAmbienteGrafico();
			}
			if (cmd == "ss") {
				jogo->CriaSala("ss");
				MostraAmbienteGrafico();
			}
			if (cmd == "e") {
				jogo->CriaSala("e");
				MostraAmbienteGrafico();
			}
			if (cmd == "sa") {
				jogo->CriaSala("sa");
				MostraAmbienteGrafico();
			}
			if (cmd == "ac") {
				jogo->CriaSala("ac");
				MostraAmbienteGrafico();
			}
			if (cmd == "or") {
				jogo->CriaSala("or");
				MostraAmbienteGrafico();
			}
			
			if (cmd == "iniciar")
			{
				if (jogo->VerificaSalas())
				{
					c.gotoxy(6, 35);
					cout << "Falta preencher salas";
					getchar();
				}
				else
					//Jogar();
			}
		}

	}
}

/*
void Interacao::Jogar()
{
	limpaParteDireita();
	jogo->turno();
	jogo->DadosViagem();
	configuracao = true;
	while (1) { //Ler comandos quando estamos a jogar
		
		regex regex_pattern("[a-z][0-9]+");
		c.gotoxy(6, 35);
		string comando, cmd;
		c.clrscr_comandline();
		getline(cin, comando);

		if (comando == "next") { // Validação para passar à próxima iteracção
			jogo->turno(); //O utilizador não quer alterar nada, e avança no turno
			MostraAmbienteGrafico();
		}
		else {
			istringstream iss(comando);
			iss >> cmd;
			//*******************************Comandos Relativos a controlo dos tripulantes************************************
			if (cmd == "mover") { //regex_match(cmd, regex_pattern
				char o[2];
				char d[2];
				char u[2];
				c.clrscr_comandline();
				c.gotoxy(5, 35);
				cout << "Unidade: ";
				cin >> u;
				c.clrscr_comandline();
				c.gotoxy(5, 35);
				cout << "Origem: ";
				cin >> o;
				c.clrscr_comandline();
				c.gotoxy(5, 35);
				cout << "Destino: ";
				cin >> d;
				jogo->Move(u, o, d);
				MostraAmbienteGrafico();
			}
		}
		jogo->gerirEvento();
	}
}
void Interacao::limpaParteDireita()
{
	int i, j;
	c.gotoxy(135, 2);
	cout << "                            ";
	for ( i = 118; i < 130; i++) {
		for ( j = 2; j < 28; j++) {
			c.gotoxy(i, j);
			cout << "                                     ";
		}
	}
	
}
*/
