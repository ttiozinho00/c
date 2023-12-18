/*

Execução: gcc -o exerc20.exe exerc20.c -pedantic -Wextra -Wall

*/

#include<stdio.h> /* printf(), scanf()*/

int main (int argc, char *argv[])
{
	int cont = 0, n, anterior, proximo, EhTripla = 0;

	argc = argc;
	argv = argv;
	
	printf ("Informe uma sequencia de valores inteiros\n");
	printf ("Digite -1 para cancelar a sequencia\n");
	
	/* Le os valores informados pelo usuário.*/
	while (n != -1)
	{
		scanf ("%d", &n);
		
		proximo = n;
		/* Verifica e conta o número de triplas.*/
		if (anterior == proximo)
		{
			cont ++;
			if (cont >= 3)
			{
				EhTripla ++;
			}
		}
		
		else
		{
			anterior = proximo;
		}

	}
	printf ("numero de triplas = %d", EhTripla);
	return 0;
}