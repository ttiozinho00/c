#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>

enum Status {CONTINUE, WON, LOST};

int rollDice(void);

int rollDice(void)
{
	int die1;
	int die2;
	int workSum;

	die1 = 1 + (rand()%6);
	die2 = 1 + (rand()%6);
	workSum = die1 + die2;

	printf("Jogador rolou %d + %d = %d\n",die1, die2, workSum);

	return workSum;
}

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	int mypoint;
	int sum;

	enum Status gameStatus;
	srand(time(NULL));
	sum = rollDice();

	switch(sum)
	{
		case 7:
		case 11:
			gameStatus = WON;
			break;

		case 2:
		case 3:
		case 12:
			gameStatus = LOST;
			break;		

		default:
			gameStatus = CONTINUE;
			mypoint = sum;

			printf("\n");
			printf("O ponto é %d\n",mypoint);	
			break;
	}

	while(gameStatus == CONTINUE)
	{
		sum = rollDice();

		if (sum == mypoint)
		{
			gameStatus = WON;
		}

		else
		{
			if (sum == 7)
			{
				gameStatus = LOST;
			}
		}

		if (gameStatus == WON)
		{
			printf("Jogador vence\n");
			printf("\n");
		}

		else
		{
			printf("Jogador perde\n");
			printf("\n");
		}
	}
	return 0;
}