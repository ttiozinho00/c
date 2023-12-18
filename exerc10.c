/*

Execução: gcc -o exerc10.exe exerc10.c -pedantic -Wextra -Wall -lm

*/
#include<stdio.h>
#include<math.h>

int main (int argc, char *argv[])
{
	int resto, div, raiz, soma, i;
	
	argc = argc;
	argv = argv;
	
	/* Percorre os valores de 1000 até 9999, divide os valores em duas dezenas,
	encontra sua raiz quadrada e soma suas dezenas.*/
	for (i = 1000; i <= 9999; i += 1)
	{
		div = i / 100;
		resto = i % 100;
		raiz = sqrt (i);
		soma = div + resto;
		
		/* Verifica se a soma das dezenas é igual sua raiz.*/
		if (soma == raiz)
		{
			printf("%d \n", i);
		}
	}
	
	return 0;
}