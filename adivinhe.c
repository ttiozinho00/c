#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	/*system("cls");*/

	argc=argc;
	argv=argv;

	int limite_superior;
	int limite_inferior;
	int tentativas;
	int acertou;
	int n;
	int x;

    srand(time(NULL));

   
    acertou = 0;           
    tentativas = 0;        
    limite_inferior = 0;    
    limite_superior = 101;  
    n = (rand() % 100) + 1; 

  
    do {
       
        system("cls");
        printf("Total de tentativas: %dn", tentativas);
        printf("Digite um numero(Esta entre %d e %d): ", limite_inferior, limite_superior);
        scanf("%d", &x);

        tentativas++;
        
        if(x > n) 
        {
            limite_superior = x;
        }

        else if(x < n) 
        {
            limite_inferior = x;
        } 

        else 
        {
            acertou = 1;
        }
    }while(!acertou);

    system("cls");
    printf("Parabens, o numero e: %dn", n);
    printf("Total de tentativas: %dn", tentativas);
	return 0;
}