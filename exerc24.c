/*
Execução: gcc -o exerc24.exe exerc24.c -pedantic -Wextra -Wall
*/

#include<stdio.h> /* printf(), scanf()*/

int main (int argc, char *argv[])
{
	int i, j; 
	char operadores[2];
	float valores[3];
	
	argc = argc;
	argv = argv;
	
	/* Le os operadores e valores.*/
	for (i = 0; i < 3; i ++)
	{
		scanf ("%f", &valores[i]);
		for (j = 0; j <= i; j ++)
		{
			scanf ("%c", &operadores[j]);
		}		
	}
	
	/* Identifica os operadores de maior  precedência.*/
	for (j = 0; j < 2; j ++)
	{
		for (i = j; i < 3; i ++)
		{
			if (operadores[j] == '/')
			{
				valores[i] /= valores[i+1];
			
			}
			
			if (operadores[j] == '*')
			{
				valores[i] *= valores[i+1];
				break;
			}
		}
	}
	
	/* Identifica os operadores restantes.*/
	for (j = 0; j < 2; j ++)
	{
		for (i = 0; i < 3; i ++)
		{
			if (operadores[j] == '+')
			{
				valores[i] += valores[i+1];
			}

			if (operadores[j] == '-')
			{
				valores[i] -= valores[i+1];
			}
		}
	}
	
	printf ("%f", valores[i]);
	
	return 0;
}
	