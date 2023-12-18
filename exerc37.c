
/*

Execução: gcc -o exerc37.exe exerc37.c -pedantic -Wextra -Wall

*/

#include <stdio.h> /*printf(), scanf() */
 
int checaPrimo(int, int);
int main(int argc, char *argv[])
{
    int num, ehPrimo;
    
    argc=argc;
    argv=argv;

    printf("Entre com um numero: ");
    scanf("%d", &num);

    ehPrimo = primeno(num, num / 2);
    if (ehPrimo == 1)
    {
        printf("%d O numero eh primo\n", num);
    }

    else
    {
        printf("%d O numero nao eh primo\n", num);
    }
    return 0;
}

//checaPrimo: função recursiva que checa se um determinado número é primo
int checaPrimo(int num, int i)
{
    if (i == 1)
    {
        return 1;
    }

    else
    {  
        if (num % i == 0) 
        {
            return 0;
        }
        
        else
        {
            return checaPrimo(num, i - 1);
        }       
    }
}