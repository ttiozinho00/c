/*

Execução: gcc -o exerc38.exe exerc38.c -pedantic -Wextra -Wall

*/

#include <stdio.h> /*printf(), scanf() */
 
int main(int argc, char *argv[])
{

    int a=0, b=0, soma=0;

    argc=argc;
    argv=argv;
    
    printf("Entre com um numero A: ");
    scanf("%d", &a);

    printf("Entre com um numero B: ");
    scanf("%d", &b);

    soma = SomaRecursiva(a+1, b, soma);

    printf("Ah soma eh: %d", soma);

    return 0;
}

int SomaRecursiva(int a, int b, int soma) 
{
    if(a==b)
    {
        return soma;
    }
    
    if(a%2==0)
    {
        soma += a;
    }

    return SomaRecursiva(a+1, b , soma);
}