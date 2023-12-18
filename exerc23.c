/*

Execução: gcc -o exerc23.exe exerc23.c -pedantic -Wextra -Wall

*/ 

#include <stdio.h> /*printf(), scanf() */

int main (int argc, char *argv[])
{
    int numero, k = 1;
    float soma=0;
	argc = argc;
	argv = argv;
	
    printf("Digite um numero: ");
    scanf("%d",&numero);

    for (k; k <= numero; k++)//5
    {
        soma = soma + 1.0 / k;
    }

    printf("H(n): %2.f", soma);

    return 0;
}