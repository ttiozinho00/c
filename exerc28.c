/*
Execução: gcc -o exerc28.exe exerc28.c -pedantic -Wextra -Wall
*/

#include <stdio.h> /* printf(), scanf()*/

int main (int argc, char *argv[])
{
	int mat[20][20], num, c, l, soma = 0, aux_soma, cont = 0;
	
	argc = argc;
	argv = argv;
	
	printf ("parametros da matriz:");
	scanf ("%d", &num);
	
	/* Leitura dos elementos da matriz*/ 
	for (l = 0; l < num; l++)
	{
		for (c = 0; c < num; c++)
		{
			scanf ("%d", &mat[l][c]);
		}
	}
	
	/* Soma dos elementos de cada coluna*/
	for (c = 0; c < num; c++)
	{
		aux_soma = soma;
		soma = 0;
		for (l = 0; l < num; l++)
			soma += mat[l][c];
		
		/* Verifica se a soma das colunas são iguais*/
		if (aux_soma != 0)
		{
			if (soma != aux_soma)
			{
				printf ("\nA matriz nao e quadrado magico");
				return 0;
			}
		}
	
	}
	
	/* Soma dos elementos de cada linha*/
	for (l = 0; l < num; l++)
	{
		soma = 0;
		for (c = 0; c < num; c++)
		{
			soma += mat[l][c];
		}
		
		/* Verifica se a soma das linhas são iguais as das colunas*/
		if (soma != aux_soma)
		{
			printf ("\nA matriz nao e quadrado magico");
			return 0;
		}
	}
	
	soma = 0;
	
	/* Soma dos elementos da diagonal principal*/
	for (l = 0; l < num; l++) 
	{
		c = cont;
		soma += mat[l][c];
		cont ++;
	}
	
	/* Verifica se a soma da diagonal principal é iguail a das colunas*/
	if (soma != aux_soma)
	{
		printf ("\nA matriz nao e quadrado magico");
		return 0;
	}
	
	/* Soma dos elementos da diagonal secundária*/
	soma = 0;
	cont = num - 1;	
	for (l = 0; l < num; l++) 
	{
		c = cont;
		soma += mat[l][c];
		cont --;
	}
	
	/* Verifica se a soma da diagonal secundária é iguail a das colunas*/
	if (soma != aux_soma)
	{
		printf ("\nA matriz nao e quadrado magico");
		return 0;
	}
		
	printf ("\nA matriz e quadrado magico");
	
	return 0;
}
	
			
			