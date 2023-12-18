/*

Execução: gcc -o exerc8.exe exerc8.c -pedantic -Wextra -Wall

*/

#include<stdio.h>
#include<stdlib.h>


int main (int argc, char *argv[])
{
	int n, valor1, valor2, i, cont, ant, comp=1, compmax=1;
	
	argc = argc;
	argv = argv;
	
	printf ("Informe o valor de n:");
	scanf ("%d", &n);
	
	printf ("Informe %d valores\n", n);
	scanf ("%d", &valor1);
	cont = 1;

	for (i = 1; i < n; i ++)
	{
    	scanf ("%d", &valor2);
     	if (valor2 > valor1)
     	{ //se o proximo for maior que o anterior, incrementa o comp;
       		comp = comp + 1 ;
     	} 

     	else
     	{
        	comp = 1; //senao o comp recebe 1;
     	}
     	
     	if (compmax < comp)
     	{
        	compmax = comp; // Se o compmax for menor que o comp, o compmax recebe o comp;
     	} 
     	valor1 = valor2;  // o valor recebe o valor2;
	}

	printf ("O comprimento do segmento crescente maximo: %d", compmax);

	return 0;
}
