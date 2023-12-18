/*

Execução: gcc -o exerc22.exe exerc22.c -pedantic -Wextra -Wall

*/

#include<stdio.h> /* printf(), scanf()*/

int main (int argc, char *argv[])
{
	int n, v[20], i, cont = 0, maior;
	
	argc = argc;
	argv = argv;
	
	scanf ("%d", &n);
	
	if (n > 0)
	{
		/* Armazena os valores fornecidos pelo usuário em um vetor.*/
		for (i = 0; i < n; i ++)
		{
			v[i] = rand () % 100;
		}
		/* Percorre o vetor verificando até onde o mesmo segue de forma crescente.*/
		for (i = 0; i < n; i ++)
		{
			if (v[i] > maior)
				{
					maior = v[i];
					cont ++;
				}
			printf ("%d", v[i]);
		}
		printf ("\n%d", cont);
	}
	return 0;
}
			
			