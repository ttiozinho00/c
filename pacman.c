#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <time.h>

#define tempoRandom() srand(time(NULL));
#define pt_br() setlocale (LC_ALL, "portuguese")
#define corJogo() system("color f")
#define limpaTela() printf("\033[H")
#define linha() printf("\n---------------------------------------------")

struct Mapa
{
	char vet_mapa[13][20], vet_pontos[13][20];
	int dificuldade;
}mapa;

struct Player
{
	char tecla, simbolo;
	int pos_i, pos_j, nav, pontos, m_pontos;
}player;

struct Fantasma
{
	char simbolo;
	int pos_i, pos_j, nav, ia;
}fantasma[4];

// funcKbhit
void funcKbhit()
{
	if(kbhit())
	{
		fflush(stdin);
		player.tecla = getch();
	}
}

// Colorir
void colorir(int F, int B) 
{
	WORD wColor = ((B & 0x0F) << 4) + (F & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

// Esconde o cursor
void esconderCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

// Arte Pac
	
void artePac()
{
	colorir(6,0);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n");
	printf("    _ __   __ _  ___ _ __ ___   __ _ _ __     \n");
	printf("   | '_ \\ / _  |/ __| '_ ` _ \\ / _` | '_ \\ \n");
	printf("   | |_) | (_| | (__| | | | | | (_| | | | |   \n");
	printf("   | .__/ \\__._|\\___|_| |_| |_|\\__,_|_| |_|\n");
	printf("   | |                                        \n");
	printf("   |_|                                        \n");
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n");
	colorir(15,0);

}

// Efeito de Loading
void loading()
{
	int i;
	printf("\n\n\n\n\n\n\n\t\t   ");
	for(i = 0; i < 3 ; i++)
	{
		printf(". ");
		usleep(200000);
	}
	system("cls");
}

// Op��es da telaInicial()
int opcoesMenu(char tecla, int nav)
{
	char dificuldade[5];
	linha();
	switch(mapa.dificuldade)
	{
		case 300000:
			strcpy(dificuldade, "Facil");
			break;

		case 200000:
			strcpy(dificuldade, "M�dio");
			break;

		case 100000:
		strcpy(dificuldade, "Dificil");
	}

	switch(nav)
	{
		case 0:

		colorir(3,0);
		printf("\n\t      >  Iniciar       ");
		colorir(15,0);
		printf("\n\t          Instru��es   ");
		printf("\n\t          Dificuldade  ");
		printf("\n\t          Pontua��o    ");
		printf("\n\t          Creditos     ");
		printf("\n\t          Sair         ");
		colorir(8,0);
		printf("\n\t\t\t\tNivel: %s", dificuldade);
		colorir(15,0);

		if(tecla == 13)
		{
			return 0;
		}
		break;

		case 1:
			
		printf("\n\t          Iniciar         ");
		colorir(3,0);
		printf("\n\t      >  Instru��es       ");
		colorir(15,0);
		printf("\n\t          Dificuldade     ");
		printf("\n\t          Pontua��o       ");
		printf("\n\t          Creditos        ");
		printf("\n\t          Sair            ");
		colorir(8,0);
		printf("\n\t\t\t\tNivel: %s", dificuldade);
		colorir(15,0);

		if(tecla == 13)
		{
			return 1;
		}
		break;

		case 2:

		printf("\n\t          Iniciar         ");
		printf("\n\t          Instru��es      ");
		colorir(3,0);
		printf("\n\t      >  Dificuldade      ");
		colorir(15,0);
		printf("\n\t          Pontua��o       ");
		printf("\n\t          Creditos        ");
		printf("\n\t          Sair            ");
		colorir(8,0);
		printf("\n\t\t\t\tNivel: %s", dificuldade);
		colorir(15,0);

		if(tecla == 13)
		{
			return 2;
		}
		break;

		case 3:

		printf("\n\t          Iniciar         ");
		printf("\n\t          Instru��es      ");
		printf("\n\t          Dificuldade     ");
		colorir(3,0);
		printf("\n\t      >  Pontua��o        ");
		colorir(15,0);
		printf("\n\t          Creditos        ");
		printf("\n\t          Sair            ");
		colorir(8,0);
		printf("\n\t\t\t\tNivel: %s", dificuldade);
		colorir(15,0);

		if(tecla == 13)
		{
			return 3;
		}
		break;

		case 4:
			
		printf("\n\t          Iniciar         ");
		printf("\n\t          Instru��es      ");
		printf("\n\t          Dificuldade     ");
		printf("\n\t          Pontua��o       ");
		colorir(3,0);
		printf("\n\t      >   Creditos         ");
		colorir(15,0);
		printf("\n\t          Sair            ");
		colorir(8,0);
		printf("\n\t\t\t\tNivel: %s", dificuldade);
		colorir(15,0);
			
		if(tecla == 13)
		{
			return 4;
		}
		break;

		case 5:
			
		printf("\n\t          Iniciar         ");
		printf("\n\t          Instru��es      ");
		printf("\n\t          Dificuldade     ");
		printf("\n\t          Pontua��o       ");
		printf("\n\t          Creditos        ");
		colorir(3,0);
		printf("\n\t      >  Sair             ");
		colorir(15,0);
		colorir(8,0);
		printf("\n\t\t\t\tNivel: %s", dificuldade);
		colorir(15,0);

		if(tecla == 13)
		{
			return 5;
		}
	}	
	linha();
	printf("\n\t         Vers�o 1.3          ");
}

// Tela de Instruções
void instrucoes()
{
	system("cls");
	loading();
	artePac();
	printf("\t\t- INSTRU�O�S -");
	linha();
	printf("\n Controle:\n");
	colorir(3,0);
	printf("\t   [W] Cima\t [A] Esquerda\n\t   [S] Baixo\t [D] Direita");
	colorir(15,0);
	linha();
	printf("\n Objetivo: \n");
	colorir(3,0);
	printf("\t   Coma todas as bolinhas sobre o \n\t   tabuleiro.\n");
	printf("\n\t   N�o deixe que os fantasmas o \n\t   toquem!");
	colorir(15,0);
	linha();
	colorir(8,0);
	printf("\n\n Pressione qualquer tecla para voltar...");
	colorir(15,0);
	system("pause > nul");
	system("cls");
	loading();
}

//Tela Dificuldade

int dificuldade()
{
	system("cls");
	loading();
	player.nav = 0;
	player.tecla = ' ';

	do
	{
		artePac();
		printf("\t\t- DIFICULDADE -");
		linha();
		funcKbhit();
		switch(player.tecla)
		{
			case 'w':
				if(player.nav > 0)
				{
					player.nav--;
					player.tecla = ' ';
				}
				break;

			case 's':
				if(player.nav < 2)
				{
					player.nav++;
					player.tecla = ' ';
				}
		}
		switch(player.nav)
		{
			case 0:
				colorir(3,0);
				printf("\n\t         >  Facil     ");
				colorir(15,0);
				printf("\n\t             Medio    ");  
				printf("\n\t             Dificil  ");
				funcKbhit();
				if(player.tecla == 13)
				{
					mapa.dificuldade = 300000;
					system("cls");
					loading();
					return 0;
				}
				break;

			case 1:
				printf("\n\t             Facil    ");
				colorir(6,0);	
				printf("\n\t          >  Medio     ");
				colorir(15,0);
				printf("\n\t             Dificil  ");
				funcKbhit();
				if(player.tecla == 13)
				{
					mapa.dificuldade = 200000;
					system("cls");
					loading();
					return 0;
				}
				break;

			case 2:
				printf("\n\t             Facil    ");
				printf("\n\t             Medio   ");
				colorir(4,0);
				printf("\n\t         >  Dificil   ");
				colorir(15,0);
				funcKbhit();
				if(player.tecla == 13)
				{
					mapa.dificuldade = 100000;
					system("cls");
					loading();
					return 0;
				}
				break;
		}
		usleep(200000);
		limpaTela();
	}while(1);	
		system("pause > nul");
		system("cls");
		loading();
}

// Tela de Pontua��o 
void pontuacao(int pontos)
{
	system("cls");
	loading();
	artePac();
	printf("\t\t- PONTUA��O -");
	linha();
	colorir(3,0);
	printf("\n\t     Pontua��o Maxima: ");
	colorir(15,0);
	printf("%d", player.m_pontos);
	colorir(8,0);
	printf("\n\n   Pressione qualquer tecla para voltar...");
	colorir(15,0);
	system("pause > nul");
	system("cls");
	loading();
}

// Tela de Créditos
void creditos()
{
	system("cls");
	loading();
	artePac();
	printf("\t\t- CREDITOS -");
	linha();
	colorir(3,0);
	printf("\n\t   Cesar Mauricio Chauchuty");
	printf("\n\t   Douglas Barreto Zanata");
	colorir(15,0);
	colorir(8,0);
	printf("\n\n Pressione qualquer tecla para voltar...");
	colorir(15,0);
	system("pause > nul");
	system("cls");
	loading();
}

// Saindo...
void sair(int cheat)
{
	int i;
	system("cls");
	usleep(500000);
	printf("\n\n\n\t\t  Saindo");

	for(i = 0; i < 3; i++)
	{
		printf(". ");
		usleep(500000);
	}
	// "Cheat"
	if(cheat == 1){
		colorir(4, 0);
		printf("\n\n");
		printf("\t  Béééééé!!!                           \n");
		printf("\n                    / /                 ");
		printf("\n                  _(.(.                 ");
		printf("\n                ,'9 )\\)`-.,.--.        ");
		printf("\n                `-.|           `.       ");
		printf("\n                   \\,      ,    \\)    ");
		printf("\n                    `.  )._\\   (\\     ");
		printf("\n                      |//   `-,//       ");
		printf("\n                      ]||    //""       ");
		printf("\n                      ""    ""          ");
		colorir(0, 0);
		sleep(2);
	}
	printf("\n\n");
	sleep(1);
	exit(0);
}

// Tela vocePerdeu()
void vocePerdeu()
{
	sleep(1);
	system("cls");
	loading();
	artePac();
	colorir(12,0);
	printf("\n\t\tVoc� perdeu.");
	colorir(15,0);
	printf("\n\n\t\tPontos: ");
	colorir(3,0);
	printf("%04d", player.pontos-20);
	colorir(8,0);
	printf("\n\n Pressione qualquer tecla para continuar...");
	colorir(15,0);
	system("pause > nul");
	system("cls");
	loading();
	telaInicial();
}

// Tela voceGanhou()
void voceGanhou()
{
	sleep(1);
	system("cls");
	loading();
	artePac();
	colorir(14,0);
	printf("\n\t\t Parabens!\n \t\tVoc� ganhou!");
	colorir(15,0);
	printf("\n\n\t\tPontos: ");
	colorir(3,0);
	printf("%04d", player.pontos-20);
	colorir(8,0);
	printf("\n\n Pressione qualquer tecla para continuar...");
	colorir(15,0);
	system("pause > nul");
	system("cls");
	loading();
	telaInicial();
}

// Controlador:
/*
   Dentro do procedimento gamePlay() temos a fun��o kbhit() combinada com getch().
   O resultado ao capturar as telas W, S, D, A e de acordo com a tecla capturada,
   movimentar o Pac dentro da Matriz (i++, i--, j++, j--)...
*/

void controle(int pos_i, int pos_j, int tam_i, int tam_j)
{
	switch(player.tecla)
	{
		case 'w':

			if(mapa.vet_mapa[pos_i-1][pos_j] == '|')
			{
				break;
			}

			if(player.pos_i != 0)
			{
				player.pos_i--;
			}
			break;

			case 's':

			if(mapa.vet_mapa[pos_i+1][pos_j] == '|')
			{
				break;
			}

			if(player.pos_i != tam_i)
			{
				player.pos_i++;
			}
			break;

			case 'a':
			if(mapa.vet_mapa[pos_i][pos_j-1] == '|')
			{
				break;
			}

			if(player.pos_j != 0)
			{
				player.pos_j--;
			}
			break;

			case 'd':
			if(mapa.vet_mapa[pos_i][pos_j+1] == '|')
			{
				break;
			}

			if(player.pos_j != tam_j)
			{
				player.pos_j++;
			}
			break;
		}	
	}

void fantasma_nav(int nav, int pos_i, int pos_j, int ia, int tam_i, int tam_j)
{
	switch(nav)
	{
		case 0:
			if(nav == 1 || nav == 2 || nav == 3)
			{
				break;
			}
		case 1:
			switch(rand() % ia){
				case 0:
					if(mapa.vet_mapa[pos_i+1][pos_j] != '|' && pos_i != tam_i){
						fantasma[nav].pos_i++;
					}
					break;
				case 1:
					if(mapa.vet_mapa[pos_i-1][pos_j] != '|' && pos_i != 0){
						fantasma[nav].pos_i--;
					}
					break;
				case 2:
					if(mapa.vet_mapa[pos_i][pos_j+1] != '|' && pos_i != tam_j){
						fantasma[nav].pos_j++;
					}
					break;
				case 3:
					if(mapa.vet_mapa[pos_i][pos_j-1] != '|' && pos_i != 0){
						fantasma[nav].pos_j--;
					}
					break;
			}
			break;
		case 2:
		case 3:
			switch(rand() % ia){
			case 0:
			case 1:
			case 2:
				if(player.pos_i < fantasma[nav].pos_i)
				{
					if(mapa.vet_mapa[pos_i-1][pos_j] != '|')
					{
						fantasma[nav].pos_i--;
					} 

					else 
					{
						switch(rand() % 2)
						{
							case 0:
								fantasma[nav].pos_j--;
								break;
							case 1:
								fantasma[nav].pos_j++;
						}
					}
				} 
				else if(player.pos_j < fantasma[nav].pos_j)
				{
					if(mapa.vet_mapa[pos_i][pos_j-1] != '|')
					{
						fantasma[nav].pos_j--;
					} 
					else 
					{
						switch(rand() % 2)
						{
							case 0:
								fantasma[nav].pos_i--;
								break;
							case 1:
								fantasma[nav].pos_i++;
						}
					}
				} 
				else if(player.pos_i > fantasma[nav].pos_i)
				{
					if(mapa.vet_mapa[pos_i+1][pos_j] != '|')
					{
						fantasma[nav].pos_i++;
					}

					else 
					{
						switch(rand() % 2)
						{
							case 0:
								fantasma[nav].pos_j--;
								break;
							case 1:
								fantasma[nav].pos_j++;
						}
					}
				} 
				else if(player.pos_j > fantasma[nav].pos_j){
					if(mapa.vet_mapa[pos_i][pos_j+1] != '|'){
						fantasma[nav].pos_j++;	
					} else {
						switch(rand() % 2){
							case 0:
								fantasma[nav].pos_i;
								break;
							case 1:
								fantasma[nav].pos_i++;
						}
					}
				}
		}			
	}
}

void gamePlay()
{
	int i, j, tam_i = 12, tam_j = 19;
	mapa.vet_mapa[13][20], mapa.vet_pontos[14][20];
	player.simbolo = 67, player.pos_i = 1, player.pos_j = 2, player.nav = 0, player.pontos = 0;
	fantasma[0].simbolo = 35,fantasma[0].pos_i = 6, fantasma[0].pos_j = 9, fantasma[0].nav = 0, fantasma[0].ia = 4;
	fantasma[1].simbolo = 36,fantasma[1].pos_i = 6, fantasma[1].pos_j = 10, fantasma[1].nav = 1, fantasma[1].ia = 4;
	fantasma[2].simbolo = 37,fantasma[2].pos_i = 7, fantasma[2].pos_j = 9, fantasma[2].nav = 2, fantasma[2].ia = 6;
	fantasma[3].simbolo = 38,fantasma[3].pos_i = 7, fantasma[3].pos_j = 10, fantasma[3].nav = 3, fantasma[3].ia = 6;
	
	loading();
	
	// Limpar Mapa Pontos
	for(i = 0; i <= tam_i; i++)
	{
		for(j = 0; j <= tam_j; j++)
		{
			mapa.vet_pontos[i][j] = ' ';
		}		
	}
	// Fim Limpar Mapa Pontos
	
	do{
		
		limpaTela();
		
		// Captura Tecla
			
		funcKbhit();
		
		// Fim Captura Tela
	
		// Controle
		controle(player.pos_i, player.pos_j, tam_i, tam_j);
		// Fim Controle
		
		// Fantasmas
		fantasma_nav(fantasma[0].nav, fantasma[0].pos_i, fantasma[0].pos_j, fantasma[0].ia, tam_i, tam_j);
		fantasma_nav(fantasma[1].nav, fantasma[1].pos_i, fantasma[1].pos_j, fantasma[1].ia, tam_i, tam_j);
		fantasma_nav(fantasma[2].nav, fantasma[2].pos_i, fantasma[2].pos_j, fantasma[2].ia, tam_i, tam_j);
		fantasma_nav(fantasma[3].nav, fantasma[3].pos_i, fantasma[3].pos_j, fantasma[3].ia, tam_i, tam_j);
		
		// Fim Fantasmas
		
	// Constru��o Mapa
		colorir(1,0);
		printf(" -------------------------------------\n");
		colorir(15,0);
		
		for(i = 0; i <= tam_i; i++)
		{
			for(j = 0; j <= tam_j; j++)
			{
				if(mapa.vet_pontos[i][j] == 'X')
				{
					mapa.vet_mapa[i][j] = 0;
				}

				else 
				{
					if(j == 0)
					{
						mapa.vet_mapa[i][j] = '|';
					}

					else if(j == 3 && (i >= 4 && i <= 8))
					{
						mapa.vet_mapa[i][j] = '|';
					}

					else if(j == 6 && (i >= 3 && i <= 9))
					{
						mapa.vet_mapa[i][j] = '|';
					}

					else if(j == 8 && (i >= 6 && i <= 7))
					{
						mapa.vet_mapa[i][j] = '|';
					}

					else if(j == 11 && (i >= 6 && i <= 7))
					{
						mapa.vet_mapa[i][j] = '|';
					}

					else if(j == 13 && (i >= 3 && i <= 9))
					{
						mapa.vet_mapa[i][j] = '|';
					}

					else if(j == 16 && (i >= 4 && i <= 8))
					{
						mapa.vet_mapa[i][j] = '|';
					}

					else if(j == tam_j)
					{
						mapa.vet_mapa[i][j] = '|';
					}

					else 
					{
						mapa.vet_mapa[i][j] = 183;
					}
				}

				mapa.vet_mapa[player.pos_i][player.pos_j] = player.simbolo;
				mapa.vet_mapa[fantasma[0].pos_i][fantasma[0].pos_j] = fantasma[0].simbolo;
				mapa.vet_mapa[fantasma[1].pos_i][fantasma[1].pos_j] = fantasma[1].simbolo;
				mapa.vet_mapa[fantasma[2].pos_i][fantasma[2].pos_j] = fantasma[2].simbolo;
				mapa.vet_mapa[fantasma[3].pos_i][fantasma[3].pos_j] = fantasma[3].simbolo;
				
				if(mapa.vet_pontos[player.pos_i][player.pos_j] != 'X')
				{
					mapa.vet_pontos[player.pos_i][player.pos_j] = 'X';
					player.pontos+= 10;

					if(player.pontos > player.m_pontos)
					{
						player.m_pontos = player.pontos - 20;
					}
						// Pontua��o Maxima 2060
					if(player.pontos >= 2060)
					{
						voceGanhou();
					}
				}
			}
		}

		for(i = 0; i <= tam_i; i++)
		{
			for(j = 0; j <= tam_j; j++)
			{
				if(mapa.vet_mapa[i][j] == player.simbolo)
				{
					colorir(14,0);
						printf("%c ", mapa.vet_mapa[i][j]);
					colorir(15,0);
				}

				else if (mapa.vet_mapa[i][j] == '#')
				{
					colorir(13,0);
						printf("%c ", mapa.vet_mapa[i][j]);
					colorir(15,0);
				}

				else if (mapa.vet_mapa[i][j] == '$')
				{
					colorir(12,0);
						printf("%c ", mapa.vet_mapa[i][j]);
					colorir(15,0);
				}

				else if (mapa.vet_mapa[i][j] == '%')
				{
					colorir(6,0);
						printf("%c ", mapa.vet_mapa[i][j]);
					colorir(15,0);
				}

				else if (mapa.vet_mapa[i][j] == '&')
				{
					colorir(11,0);
						printf("%c ", mapa.vet_mapa[i][j]);
					colorir(15,0);
				}

				else if(mapa.vet_mapa[i][j] == '|')
				{
					colorir(1,0);
					printf("%c ", mapa.vet_mapa[i][j]);
					colorir(15,0);
				}

				else 
				{
					printf("%c ", mapa.vet_mapa[i][j]);
				}
			}
			printf("\n");
		}

		if((player.pos_i == fantasma[0].pos_i && player.pos_j == fantasma[0].pos_j))
		{
			vocePerdeu();
		}

		else if((player.pos_i == fantasma[1].pos_i && player.pos_j == fantasma[1].pos_j)) 
		{
			vocePerdeu();
		}

		else if((player.pos_i == fantasma[2].pos_i && player.pos_j == fantasma[2].pos_j)) 
		{
			vocePerdeu();
		}

		else if((player.pos_i == fantasma[3].pos_i && player.pos_j == fantasma[3].pos_j)) 
		{
			vocePerdeu();
		}

		colorir(1,0);
		printf(" -------------------------------------\n");
		colorir(15,0);
		
		// Pontua��o 
		colorir(8,0);
		printf("\n\t\t\t   Pontos: ");
		colorir(15,0);
		printf("%04d  ", player.pontos-10);
		colorir(15,0);
		
		// Fim Pontua��o
		
		if(player.simbolo == 67 && player.pontos > 1)
		{
			player.simbolo = 79;
		}

		else 
		{
			player.simbolo = 67;
		}
		usleep(mapa.dificuldade);
		// Fim Construa��o Mapa
	
	}while(1);
}

int telaInicial()
{
	char vet_efeito[23];
	char pac;
	int pos_pac;
	int pontos;
	int cheat;
	int i;

	pos_pac = 0;
	pontos = 0;
	cheat = 0;
	pac = 67;

	player.tecla = ' ';
	player.nav = 0;
		
	do
	{
		
		// Arte Pacman
		artePac();
		// Fim Arte Pacman
		
		// Efeito Pacman
		for(i = 0; i <= 22; i++)
		{
			if(pos_pac == i)
			{
				if(pac == 67)
				{
					pac = 79;
					vet_efeito[i] = pac;
				}

				else 
				{
					pac = 67;
					vet_efeito[i] = pac;
				}
			}

			else
			{
				if(i >= pos_pac)
				{
					vet_efeito[i] = 183;
				}

				else 
				{
					vet_efeito[pos_pac-1] = 0;
				}
			}
		}
		
		for(i = 0; i <= 21; i++)
		{
			printf(" %c", vet_efeito[i]);
		}
		
		pos_pac++;
		
		if(pos_pac > 22)
		{
			pos_pac = 0;
		}
		// Fim Efeito Pacman
		
		// Menu
		
		// Controle
		if(kbhit())
		{
			fflush(stdin);
			player.tecla = getch();
			if((player.tecla == 'w') && player.nav > 0)
			{
				player.nav--;
			}

			else if((player.tecla == 's') && player.nav < 5)
			{
				player.nav++;
			}

			if(player.tecla == 'c')
			{
				cheat = 1;
			}
		}
		
		// Op��es Menu
		switch(opcoesMenu(player.tecla, player.nav))
		{
			case 0:
				system("cls");
				gamePlay();
				player.tecla = ' ';
				break;

			case 1:
				instrucoes();
				player.tecla = ' ';
				break;

			case 2:
				dificuldade();
				player.tecla = ' ';
				break;

			case 3:
				pontuacao(pontos);
				player.tecla = ' ';
				break;

			case 4:
				creditos();
				player.tecla = ' ';
				break;

			case 5:
				sair(cheat);
				break;
		}
				
		// Fim Controle
		
		// Fim Menu
		usleep(150000);
		limpaTela();		
	}while(0 == NULL);
	
	return 0;
}

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	mapa.dificuldade = 300000;
	// Procedimentos Gerais
	esconderCursor();
	tempoRandom();
	pt_br();
	corJogo();
	// Fim Procedimentos Gerais
	
	// Tela Inicial
	telaInicial();
	// Fim Tela Inicial
	return 0;
}
