#include "Interacao.h"
#include "Jogo.h"
class Evento;

Interacao::Interacao()
{
		jogo_criado = false; //O jogador ainda nao iniciou o jogo
}
void Interacao::Entrada()
{
	c.setTextSize(8, 8); //Temos de diminuir o tamanho da letra para caber dentro da janela
	c.setScreenSize(95, 85);  //Valores muito altos podem nao dar
	c.setBackgroundColor(c.PRETO);  //Utilizar o c.Preto para aceder a constante para o Preto
	c.setTextColor(c.BRANCO_CLARO);
	c.clrscr();
	ifstream myReadFile;
	myReadFile.open("Entrada.txt");
	char output[100];
	if (myReadFile.is_open()) {  //Ler todo o ficheiro Entrada.txt e desenhar caracteres
		while (!myReadFile.eof()) {

			myReadFile >> output;
			cout << output;
			cout << endl;

		}
		myReadFile.close();
	}
	c.setTextSize(8, 8);
	c.setTextColor(c.VERMELHO_CLARO);
	cout << "\n****************   OOOOOOOOOOOO)) OOOOOOOOOOOOO)) O))               ****************  \n";
	cout << "****************   O))                  O))       O))               ****************  \n";
	cout << "****************   O))                  O))       O))               ****************  \n";
	cout << "****************   OOOOOO))             O))       O))               ****************  \n";
	cout << "****************   O))                  O))       O))               ****************  \n";
	cout << "****************   O))                  O))       O))               ****************  \n";
	cout << "****************   O))                  O))       OOOOOOOOOOOOO))   ****************  \n";
	c.gotoxy(35, 92);
	c.setTextColor(c.AMARELO_CLARO);
	cout << "<<INSERT COIN!>>\n";
	getchar();
	c.clrscr();
	c.setTextColor(c.BRANCO_CLARO);
	c.setBackgroundColor(c.PRETO);  // favor consultar o .h para ver as constantes
	c.setTextColor(c.BRANCO_CLARO);
	c.setScreenSize(80, 100);
}
void Interacao::Novo_Jogo()
{
	string n;

	regex regex_pattern("^[1-9]+$");
	do
	{
		c.gotoxy(3, 35);
		c.clrscr_comandline();
		cout << "Indique a Dificuldade do jogo: ";
		cin >> n;
	} while (!regex_match(n, regex_pattern));

	int valor = atoi(n.c_str()); //converter string n para inteiro
	jogo = new Jogo(valor);
}
void Interacao::MostraAmbienteGrafico()
{
	c.setScreenSize(100, 170);
	c.setTextSize(16, 16);
	c.clrscr();
	/*Desenhar janela esquerda onde vai estar a nave*/
	c.gotoxy(1, 1);
	
	for (int i = 0; i < 115; i++) //Desenhar linha horizontal superior da janela
		cout << char(220);

	c.gotoxy(1, 30);
	for (int i = 0; i < 115; i++) //Desenhar linha horizontal inferior da janela
		cout << char(220);

	for (int j = 2; j < 31; j++) //Desenhar linha vertical esquerda da janela
		{
			c.gotoxy(1, j);
			cout << char(178);
		}

	for (int j = 2; j < 31; j++) //Desenhar linha vertical direita da janela
	{
		c.gotoxy(115, j);
		cout << char(178);
	}


	/*Desenhar janela direita onde vai estar o historico de eventos*/
	c.gotoxy(117, 1);
	for (int i = 0; i < 50; i++) //Desenhar linha horizontal superior da janela
		cout << char(220);

	c.gotoxy(117, 30);
	for (int i = 0; i < 50; i++) //Desenhar linha horizontal inferior da janela
		cout << char(220);

	for (int j = 2; j < 31; j++) //Desenhar linha vertical esquerda da janela
	{
		c.gotoxy(117, j);
		cout << char(178);
	}

	for (int j = 2; j < 31; j++) //Desenhar linha vertical direita da janela
	{
		c.gotoxy(166, j);
		cout << char(178);
	}

	/*Desenhar janela direita onde vai estar a linha de comandos*/
	c.gotoxy(1, 32);
	for (int i = 0; i < 166; i++) //Desenhar linha horizontal superior da janela
		cout << char(220);

	c.gotoxy(1, 37);
	for (int i = 0; i < 166; i++) //Desenhar linha horizontal inferior da janela
		cout << char(220);

	for (int j = 33; j < 38; j++) //Desenhar linha vertical esquerda da janela
	{
		c.gotoxy(1, j);
		cout << char(178);
	}

	for (int j = 33; j < 38; j++) //Desenhar linha vertical direita da janela
	{
		c.gotoxy(166, j);
		cout << char(178);
	}

	/*////////////////////////////////DESENHAR NAVE/////////////////////////////////////////*/
	
	c.gotoxy(5, 3);
	for (int i = 0; i < 81; i++)		//Primeira Linha
		cout << char(178);				//Desenha linha
	c.gotoxy(5, 11);				    //Posição da linha seguinte
	for (int i = 0; i < 101; i++)		//Segunda Linha
		cout << char(178);
	
	c.gotoxy(5, 19);					//Posição da linha seguinte
	for (int i = 0; i < 101; i++)		//Terceira Linha
		cout << char(178);
	
	c.gotoxy(5, 28);					//Posição da linha seguinte
	for (int i = 0; i < 81; i++)		//Quarta Linha
		cout << char(178);

	for (int i = 5; i <90; i = i + 20) //Ciclo para desenhar colunas da primeira linha da nave
	{
		for (int j = 4; j < 11; j++)    //Cada espaçamente entre as linhas tem 8 caracteres
		{
			c.gotoxy(i, j);
			cout << char(178);
		}
	}

	for (int i = 25; i < 110; i = i + 20) //Ciclo para desenhar colunas da segunda linha da nave
	{
		for (int j = 12; j < 19; j++) //Cada espaçamente entre as linhas tem 8 caracteres
		{
			c.gotoxy(i, j);
			cout << char(178);
		}
	}
	
	for (int i = 5; i < 90; i = i + 20) //Ciclo para desenhar colunas da terceira linha da nave
	{
		for (int j = 20; j < 29; j++) //Cada espaçamente entre as linhas tem 5 caracteres
		{
			c.gotoxy(i, j);
			cout << char(178);
		}
	}
	c.gotoxy(70, 33);
	cout << "<<Comandos>>";
	c.gotoxy(3, 35);
	cout << ">>:";

	/*********************************************Desenhar Salas****************************************/
	int x = 6;
	int y = 6;
	for (unsigned int i = 0; i < 12; i++)
	{
		c.gotoxy(x, y);
		cout << jogo->getNomeSala(i);
		if (jogo->getNomeSala(i) != "?")
		{
			//Integridade  nesta sala
			c.gotoxy(x, y + 1);
			cout << "I: " << jogo->getIntegridade(i);
			//Oxigenio  nesta sala
			c.gotoxy(x, y + 2);
			cout << "O: " << jogo->getOxigenio(i);
			//Unidades que estao nesta sala
			c.gotoxy(x, y + 3);
			cout << "U: " << jogo->getUnidades(i);
			//*****//
		}
		x = x + 20;
		if (x == 86)
		{
			x = 28;
			y = 14;
		}
		if (x == 108 && y == 14)
		{
			x = 6;
			y = 23;
		}
	}
	/*****************************************Acabou de Desenhar Salas**************************************/
	if (configuracao == false)
		{
			Jogo_A_Iniciar();
			c.gotoxy(120, 15);
			cout << "Tripulantes disponiveis para mover: ";
			c.gotoxy(120, 16);
			jogo->TripulantesDisponiveis();
		}
	else
	{
		jogo->DadosViagem();
	}
}
void Interacao::Jogo_A_Iniciar()
{

	/*************************************Mostrar comandos disponiveis********************************/
	c.gotoxy(135, 2);
	cout << "Configure a nave: ";
	c.gotoxy(120, 3);
	cout << "Comandos: ";
	c.gotoxy(120, 4);
	cout << "pa -> Propulsores Adicionais";
	c.gotoxy(120, 5);
	cout << "b -> Beliche";
	c.gotoxy(120, 6);
	cout << "rl -> Raio Laser";
	c.gotoxy(120, 7);
	cout << "ar -> Auto-Reparador";
	c.gotoxy(120, 8);
	cout << "ss -> Sistema de Seguranca Interno";
	c.gotoxy(120, 9);
	cout << "e -> Enfermaria";
	c.gotoxy(120, 10);
	cout << "sa -> Sala de Armas";
	c.gotoxy(120, 11);
	cout << "ac -> Alojamentos do Capitao";
	c.gotoxy(120, 12);
	cout << "or -> Oficina Robotica";

}
void Interacao::Configurar_Nave() {
	//regex regex_pattern("\s");
	
	while (1) {
		
		c.gotoxy(6, 35);
		string comando, cmd;
		c.clrscr_comandline();
		getline(cin, comando);

		if (cmd == "next") // passar para próxima iteracção
			next();
		else {
			istringstream iss(comando);
			iss >> cmd;

			//******************************* Comandos Relativos a Configuração da Nave ************************************
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
			
			if (cmd == "next")
			{
				if (jogo->VerificaSalas())
				{
					c.gotoxy(6, 35);
					cout << "Falta preencher salas";
					getchar();
				}
				else
					Jogar();
			}
		}

	}
}
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

