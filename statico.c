#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void staticArrayInit(void);
void automaticArrayInit(void);

void staticArrayInit(void)
{
	static int array1[3];
	int i;

	printf("\nValores na entrada de staticArrayInit:\n");

	for (i = 0; i <= 2; i++)
	{
		printf("\n");
		printf("array1[%d] = %d",i, array1[i]);
	}

	printf("\n");
	printf("\nValores na saída de staticArrayInit:\n");

	for (i = 0; i <= 2; i++)
	{
		printf("\n");
		printf("array1[%d] = %d",i, array1[ i ] += 5);
	}
}

void automaticArrayInit(void)
{
	int array2[3] = {1,2,3};
	int i;

	printf("\n");
	printf("\nValores na entrada de automaticArrayInit:\n");
	printf("\n");

	for (i = 0; i <= 2; i++)
	{
		printf("\n");
		printf("array2[ %d ] = %d",i,array2[i]);
	}

	printf("\n");
	printf("\n Valores na saída de automaticArrayInit:\n");
	printf("\n");

	for (i = 0; i <= 2; i++)
	{
		printf("\n");
		printf("array2[%d] = %d",i,array2[ i ] += 5);
	}
}

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	printf("\n\n Primeira chamada para cada função:\n");
	staticArrayInit();
	automaticArrayInit();

	printf("\n");
	printf("\n\n segunda chamada para cada função:\n");
	staticArrayInit();
	automaticArrayInit();

	return 0;
}