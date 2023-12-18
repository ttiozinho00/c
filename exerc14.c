/*

Execução: gcc -o exerc14.exe exerc14.c -pedantic -Wextra -Wall

*/

#include<stdio.h> /* printf(), scanf()*/

int main (int argc, char *argv[])
{
	int n_lin, n_col, l, c, aux1, aux2;
	
	argc = argc;
	argv = argv;
	
	scanf ("%d", &n_lin);
	/* Define o numero de asteriscos que a base do triângulo deve conter.*/
	n_col = n_lin + (n_lin - 1);
	
	/* Encontra o meio do triângulo.*/
	aux1 = n_col / 2;
	aux2 = aux1 + 2;
	
	/* Percorre as linhas e colunas para imprimir os asteriscos na tela.*/
	for (l = 0; l < n_lin; l++)
	{
		for (c = 0; c < n_col; c++)
		{
			/* Define as posições em que os asteriscos devem ser impressos.*/
			if (c > aux1 && c < aux2)
			{
				printf ("*");
			}
			
			else
			{
				printf (" ");
			}
		}
		aux1 -= 1;
		aux2 += 1;
		
		printf ("\n");
	}
	
	return 0;
}