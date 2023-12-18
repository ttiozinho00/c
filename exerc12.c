/*

Execução: gcc -o exerc12.exe exerc12.c -pedantic -Wextra -Wall

*/

#include<stdio.h> /* printf(), scanf()*/

int main (int argc, char *argv[])
{
	int h, lin, col, aux1, aux2;
	
	argc = argc;
	argv = argv;
	
	scanf ("%d", &h);
	
	/* verifica se o numero definido pelo usuário é maior que zero.*/
	if (h > 0)
	{
		aux1 = 1;
		aux2 = h;
		
		/* Percorre as linhas e colunas para imprimir a letra "X" na tela.*/
		for (lin = 1; lin <= h; lin ++)
		{
			for (col = 1; col <= h; col ++)
			{
				/* Define as posições em que o "X" deve ser impresso, de acordo com 
				os valores estabelecidos pelas variaveis auxiliares (aux1 e aux2).*/

				if (col == aux1 || col == aux2)
				{
					printf ("X");
				}

				else
				{
					printf (" ");
				}
			}
			printf ("\n");
			
			aux1 ++;
			aux2 --;
		}
	}
	
	else
	{
		printf ("numero invalido");
	}
	return 0;
}