/*

Execução: gcc -o exerc17.exe exerc17.c -pedantic -Wextra -Wall

*/

#include <stdio.h> //scanf(), printf()
#include <math.h> //necessária para usar as funções matemáticas, log2()


int main (int argc, char *argv[])
{
    int numero = 0;
    	
	argc = argc;
	argv = argv;

    printf("Digite o numero para calcular o log2(X): ");
    scanf("%d", &numero);

    printf("Log(%d) = %2.f", numero, log2(numero));

    return 0;
}