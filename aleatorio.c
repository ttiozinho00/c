#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	int totalDivisores;
	int nMax;
	int i;
	int j;

    printf("Digite o limite superior para os numeros primos(Minimo 2): ");
    scanf("%d", &nMax);

    while(nMax < 2) 
    {
        system("cls");
        printf("Digite o limite superior para os numeros primos(Minimo 2): ");
        scanf("%d", &nMax);
    }

    for(i = 0; i <= nMax; i++) 
    {
        totalDivisores = 0;
   
        for(j = 1; j <= i; j++) 
        {
            if(i % j == 0) 
            {
                totalDivisores++;
            }
        }
       
        if(totalDivisores == 2) 
        {
            printf("%4d ", i);
        }
    }

	return 0;
}