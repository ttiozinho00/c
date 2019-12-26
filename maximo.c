#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int maximum(int x, int y, int z);

int maximum(int x, int y, int z)
{
	int max = x;

	if (y > max)
	{
		max = y;
	}

	if (z > max)
	{
		max = z;
	}

	return max;
}

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	int num1;
	int num2;
	int num3;

	printf("Informe o primeiro numero:");
	scanf("%d",&num1);

	printf("Informe o segundo numero:");
	scanf("%d",&num2);

	printf("Informe o terceiro numero:");
	scanf("%d",&num3);

	printf("\n");
	printf("Máximo é:%d\n",maximum(num1,num2,num3));

	return 0;
}