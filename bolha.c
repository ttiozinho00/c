#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAM 7

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	int vetor[TAM];
	int aux;
	int y;
	int x;

	for (x = 0;x < TAM;x++)
	{
		for(y = x + 1; y < TAM; y++)
		{
			if (vetor[x] > vetor[y])
			{
				aux = vetor[x];
         		vetor[x] = vetor[y];
         		vetor[y] = aux;
			}
		}		
	}		

	printf(" Elementos ordenados (Decrescente):");

	for (x = 0;x < TAM;x++)
	{
		printf("\n");
		printf(" vetor[%d] = %d",x,vetor[x]);
	}
	printf("\n");

	return 0;
}