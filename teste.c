#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argv=argv;
	argc=argc;

	float result;
	int a;
	int b;

	printf("Informe o primeiro valor:");
	scanf("%d",&a);

	printf("Informe o segundo valor:");
	scanf("%d",&b);

	result = pow(a,b)/2;


	if (result <= 10)
	{
		printf("\n");
		printf("O numero e maior!");
	}

	else
	{
		printf("\n");
		printf("O numero e menor!");
	}

	return 0;
}