
/*

Execução: gcc -o exerc19.exe exerc19.c -pedantic -Wextra -Wall

*/

#include <stdio.h> /*printf() */

int main (int argc, char *argv[])
{
    int q, j, n, i = 1;
    double soma = 0.0, qf = 0.0;

    argc=argc;
    argv=argv;

    printf("Digite q, j e n: ");
    scanf("%d %d %d", &q, &j, &n);

    for (i; i <= n; i++)
    {
        soma = soma + ((1 + (j / 100)) * i);
    }
    
    qf = q * soma;
    printf("A quantia final qf eh : %f", qf);

    return 0;
}