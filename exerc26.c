/*
Execução: gcc -o exerc26.exe exerc26.c -pedantic -Wextra -Wall
*/

#include<stdio.h> /* printf(), scanf()*/

int main (int argc, char *argv[])
{
	int mat[20][20], col, lin, c, l, cont1 = 0, cont2 = 0, soma;
	
	argc = argc;
	argv = argv;
	
	printf ("numero de linhas:");
	scanf ("%d", &lin);
	
	printf ("numero de colunas:");
	scanf ("%d", &col);
	
	/* Armazena os valores fornecidos pelo usuário em uma matriz.*/
	for (l = 0; l < lin; l++)
	{
		for (c = 0; c < col; c++)
		{
			scanf ("%d", &mat[l][c]);
		}
	}
	
	/* Percorre as colunas da matriz verificando se as mesmas são nulas.*/
	for (c = 0; c < col; c++)
	{
		soma = 0;
		for (l = 0; l < lin; l++)
		{
			soma += mat[l][c];
		}
		
		if (soma == 0)
		{
			cont1 ++;
		}
	}
	
	/* Percorre as linhas da matriz verificando se as mesmas são nulas.*/
	for (l = 0; l < lin; l++)
	{
		soma = 0;
		for (c = 0; c < col; c++)
		{
			soma += mat[l][c];
		}
		
		if (soma == 0)
		{
			cont2 ++;
		}
	}
	
	printf ("\nLinhas nulas = %d", cont2);
	printf ("\nColunas nulas = %d", cont1);
	
	return 0;
}
	
			
			