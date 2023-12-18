/*

Execução: gcc -o exerc36.exe exerc36.c -pedantic -Wextra -Wall

*/

#include<stdio.h> /* printf(), scanf()*/

int SomaDigitos(int numero, int soma)
{
	int resto;
	/* Verifica se a divisão dos digitos foi concluida e retorna o valor da soma.*/
	if (numero == 0)
	{
		return soma;
	}
	
	/* Separa e soma os digitos do valor recebido.*/
	if (numero != 0)
	{
		resto = numero %10;
		soma += resto;
		numero /= 10;
	}
	return SomaDigitos(numero, soma);        
}

int main(int argc, char *argv[])
{
	int numero, soma;
	
	argc = argc;
	argv = argv;
	soma = 0; 
	
	printf ("Informe um valor inteiro:");
	scanf ("%d", &numero);
	
	soma = SomaDigitos(numero, soma);
	printf ("A resultado da soma dos digitos e %d\n", soma);
	
	return 0;
}