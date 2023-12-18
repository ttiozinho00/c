/*

Execução: gcc -o exerc29.exe exerc29.c -pedantic -Wextra -Wall

*/

#include<stdio.h> /* printf(), scanf()*/

int main (int argc, char *argv[])
{
	int num, mat[20][20], lin, col;
	
	argc = argc;
	argv = argv;
	
	scanf ("%d", &num);
	
	/* Preenche a matriz com zeros*/
	for (lin = 0; lin < num; lin++)
	{
		for (col = 0; col < num; col++)
		{
			mat[lin][col] = 0;
		}
	}
	
	/* Preenche a primeira coluna com valor um*/
	for (lin = 0; lin < num; lin++)
	{
		mat[lin][0] = 1;
	}
	
	/* Executa a soma dos valores da linha superior e armazena na linha inferior*/
	for(lin = 1; lin < num; lin++)
	{
		for (col = 1; col < num; col++)
		{
			mat[lin][col] = mat[lin - 1][col] + mat[lin - 1][col - 1];
		}
	}
	
	/* Percorre a matriz para imprimir os valores na tela*/
	for (lin = 0; lin < num; lin++)
	{
		for (col = 0; col < num; col++)
		{
			/* Verifica se os valores da matriz são diferentes de zero, para imprimilos na tela*/
			if (mat[lin][col] != 0)
			{
				printf ("%d ",mat[lin][col]);
			}
		}
		printf ("\n");
	}
	
	return 0;
}
			