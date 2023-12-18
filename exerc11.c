/*

Execução: gcc -o exerc11.exe exerc11.c -pedantic -Wextra -Wall

*/

#include<stdio.h> /* printf(), scanf()*/

int main (int argc, char *argv[])
{
	int n, valor1, valor2, i, cont;
	
	argc = argc;
	argv = argv;
	
	printf ("Informe o valor de n:");
	scanf ("%d", &n);
	
	printf ("Informe %d valores\n", n);
	scanf ("%d", &valor1);
	cont = 1;
	
	/* Faz a leitura de n valores digitados pelo usuário.*/
	for (i = 1; i < n; i += 1)
	{
		scanf ("%d", &valor2);
		
		/* Verifica se o valor digitado anteriormente é igual ao atual.*/
		if (valor1 != valor2)
		{
			cont += 1;
			valor1 = valor2;
		}
	}
	
	printf ("A sequencia e formada por %d segmentos de numeros iguais", cont);
	
	return 0;
}