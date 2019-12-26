#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argv=argv;
	argc=argc;

	float resultado;
	float a;
	float b;
	float c;

	printf("\n Digite o valor de a:");
    scanf ("%f",&a);

    printf("\n Digite o valor de b:");
    scanf ("%f",&b);

    printf("\n Digite o valor de c:");
    scanf ("%f",&c);
 
 	resultado=(a*b)/c;
 
 	printf("\n O resultado e : %.2f",resultado);
 
	return 0;
}