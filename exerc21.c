/*

Execução: gcc -o exerc21.exe exerc21.c -pedantic -Wextra -Wall

*/

#include<stdio.h> /* printf(), scanf()*/
#include<math.h> /* Operações matemáticas */

int main (int argc, char *argv[])
{
	int n, resto, div, cont = 0, soma = 0, mult;
	
	argc = argc;
	argv = argv;
	
	scanf ("%d", &n);
	div = n;
	
	/* Separa os digitos do valor fornecido pelo usuário.*/
	while (div != 0)
	{
		resto = div % 10;
		div /= 10;
		/* Verifica se o numero fornecido pelo usuário pertence a base octal.
		 Se pertencer realiza a conversão*/
		if (resto < 8)
		{
			mult = resto * pow(8, cont);
			soma += mult;
			cont ++;
		}
		
		else
		{
			printf("Esse valor nao e octal");
			return 0;
		}
	}	

	
	printf ("%d", soma);
	
	return 0;
}