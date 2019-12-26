#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define TAMANHO 5

int main(int argc, char const *argv[])
{
	system("cls");

	argv=argv;
	argc=argc;

	int matriz[TAMANHO][TAMANHO];
	int coluna;
	int linha;


	srand(time(NULL));

	for (linha = 0; linha < TAMANHO; linha++)
	{
		for (coluna = 0; coluna < TAMANHO; coluna++)
		{
			matriz[linha][coluna] = rand();
			printf("%d\n",matriz[linha][coluna]);
		}
	}

	return 0;
}