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
	else {
		ComandosJogo();
	}
	

	Consola::gotoxy(75, 50);
	cout << "<<Comandos>>";
	Consola::gotoxy(3, 52);
	cout << ">>:";
	
	
	/*********************************************Desenhar castelos/seres****************************************/


	
	/*****************************************Acabou de Desenhar Salas**************************************/
	

}

void Interacao::MostraMundo(int foco){
	int inicio = 0, fim = 0;
	int aux = 0;

	//inicio = jogo->getMyColonia()->getPosInicial() - 12;
	inicio = foco - 12;
	fim = foco + 12;

	if (inicio < 0) {
		aux = inicio*(-1);
		inicio = 0;
		fim = fim + aux;
	}
	else if ((jogo->getMundo().size() - 1) < fim) {
		aux = fim - (jogo->getMundo().size() - 1);
		inicio = inicio - aux;
		fim = jogo->getMundo().size() - 1;
	}






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

void Interacao::Configurar_Jogo() {

	while (1) {
		Consola::gotoxy(6, 35);
		string comando, cmd;
		int dim = -1, money = -1, opo = -1;
		
		Consola::clrscr_comandline();
		getline(cin, comando);

		if (cmd == "dim") {
			int lin,col;
			Consola::clrscr_comandline();
			Consola::gotoxy(5, 35);
			cout << "Linhas: ";
			cin >> lin;
			Consola::clrscr_comandline();
			Consola::gotoxy(5, 35);
			cout << "Colunas: ";
			cin >> col;
			dim = lin*col;
			jogo->criaMundo(dim);
		}
		if (cmd == "moedas") {
			int moedas;
			Consola::clrscr_comandline();
			Consola::gotoxy(5, 35);
			cout << "Num moedas: ";
			cin >> moedas;
			money = moedas;
			jogo->criaMyColonia(money);
		}
		if (cmd == "oponentes") {
			int oponentes;
			Consola::clrscr_comandline();
			Consola::gotoxy(5, 35);
			cout << "Num oponentes: ";
			cin >> oponentes;
			opo = oponentes;
			jogo->criaColOponentes(1000, opo);
		}
		if (cmd == "castelo") {
			string nome;
			int l, c;
			Consola::clrscr_comandline();
			Consola::gotoxy(5, 35);
			cout << "Nome Castelo: ";
			cin >> nome;
			Consola::clrscr_comandline();
			Consola::gotoxy(5, 35);
			cout << "Linhas: ";
			cin >> l;
			Consola::clrscr_comandline();
			Consola::gotoxy(5, 35);
			cout << "Colunas: ";
			cin >> c;
			int pos = l*c;
			jogo->getMyColonia()->setPosInicial(pos);
			
		}
		if (cmd == "mkperfil") {
			char perfil;
			Consola::clrscr_comandline();
			Consola::gotoxy(5, 35);
			cout << "Letra para o perfil: ";
			cin >> perfil;

			jogo->addPerfil(new Perfil(perfil));
		}
		if (cmd == "addperfil") {
			char perf;
			int idCar;
			Consola::clrscr_comandline();
			Consola::gotoxy(5, 35);
			cout << "Letra para o perfil: ";
			cin >> perf;
			Consola::clrscr_comandline();
			Consola::gotoxy(5, 35);
			cout << "ID da Caracteristica: ";
			cin >> idCar;

			jogo->addCarAoPerfil(perf, idCar);
		}
		if (cmd == "subperfil") {
			char perf;
			int idC;
			Consola::clrscr_comandline();
			Consola::gotoxy(5, 35);
			cout << "Letra para o perfil: ";
			cin >> perf;
			Consola::clrscr_comandline();
			Consola::gotoxy(5, 35);
			cout << "ID da Caracteristica: ";
			cin >> idC;

			jogo->removeCarAoPerfil(perf, idC);
		}
		if (cmd == "rmperfil") {
			char p;
			Consola::clrscr_comandline();
			Consola::gotoxy(5, 35);
			cout << "Letra para o perfil: ";
			cin >> p;

			jogo->removePerfil(p);
		}
		if (cmd == "load") {
			string fich;
			Consola::clrscr_comandline();
			Consola::gotoxy(5, 35);
			cout << "Nome do ficheiro: ";
			cin >> fich;

			jogo->loadFicheiro(fich);
		}
		if (cmd == "inicio") {
			if (dim == -1 && money == -1 && opo == -1)
			{
				Consola::gotoxy(6, 35);
				cout << "Falta preencher parametros...";
				getchar();
			}
			else {
				jogo_criado = true;
				jogo->ComecarAJogar();
				Jogar();
			}
		}

		
	}
}


void Interacao::ComandosJogo() {

	/*************************************Mostrar comandos disponiveis********************************/
	Consola::gotoxy(193, 2);
	cout << " Jogo: ";
	Consola::gotoxy(155, 4);
	cout << "Comandos: ";
	Consola::gotoxy(155, 6);
	cout << "foco lin col -> Foco da planicie";
	Consola::gotoxy(155, 8);
	cout << "setmoedas colonia num -> Adiciona ou retira moedas a uma colonia";
	Consola::gotoxy(155, 10);
	cout << "build edif lin col -> Constroi um edif nas coordenadas";
	Consola::gotoxy(155, 12);
	cout << "list colonia -> Lista tudo sobre a colonia";
	Consola::gotoxy(155, 14);
	cout << "list perfil -> Apresenta detalhes de um perfil";
	Consola::gotoxy(155, 16);
	cout << "listallp -> Apresenta detalhes de todos os perfis";
	Consola::gotoxy(155, 18);
	cout << "mkbuild edif lin col colonia -> Add um edif a uma colonia nas coordenadas";
	Consola::gotoxy(155, 20);
	cout << "repair EID -> Repara o edif indicado pelo id da colonia do jogador";
	Consola::gotoxy(155, 22);
	cout << "upgrade EID -> Melhora um dado edif";
	Consola::gotoxy(155, 24);
	cout << "ser num perf -> Cria um ser com um dado perfil";
	Consola::gotoxy(155, 26);
	cout << "next -> Avanca um instante";
	Consola::gotoxy(155, 28);
	cout << "next num -> Avanca num instantes";
	Consola::gotoxy(155, 30);
	cout << "ataca -> Faz os seres da colon do jogador sairem do cast, ativar caract";
	Consola::gotoxy(155, 32);
	cout << "ser num perf -> Cria um ser com um dado perfil";
	Consola::gotoxy(155, 34);
	cout << "recolhe -> Chama os seres para o castelo";
	Consola::gotoxy(155, 36);
	cout << "fim -> Termina a simulacao";
	Consola::gotoxy(155, 38);
	cout << "load ficheiro -> Carrega comandos de um ficheiro";
}


void Interacao::Jogar()
{
	limpaParteDireita();
	ComandosJogo();
	jogo->turno();
	jogo->DadosJogo();
	configuracao = true;
	while (1) { //Ler comandos quando estamos a jogar
		
		regex regex_pattern("[a-z][0-9]+");
		Consola::gotoxy(6, 35);
		string comando, cmd;
		Consola::clrscr_comandline();
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
				jogo->Move(u, o, d);
				MostraAmbienteGrafico();
			}
		}
		jogo->gerirEvento();
	}
}
void Interacao::limpaParteDireita()
{
	
	Consola::gotoxy(190, 2);
	cout << "                                               ";
	Consola::gotoxy(155, 4);
	int i, j;
	Consola::gotoxy(155, 4);
	cout << "                                               ";
	for ( i = 4; i < 30; i=i+2) {
		Consola::gotoxy(155, i);
		cout << "                                            ";
		
	}
	
}

