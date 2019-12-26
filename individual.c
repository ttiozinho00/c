#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define SIZE 5

void modifyArray(int b[], int size);
void modifyElement(int e);

void modifyArray(int b[], int size)
{
	int j;

	for (j = 0; j < size; j++)
	{
		b[j] *= 2;
	}
}

void modifyElement(int e)
{
	printf("Valor em modifyElement é %d\n",e *= 2);
}


int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	int a[SIZE] = {0, 1, 2, 3, 4}; 
	int i;

	printf("Efeitos da passagem do array inteiro por referência:Os valores o array original são:\n”");
	
	for (i = 0; i < SIZE; i++)
	{
		printf("%3d",a[i]);
	}

	printf("\n");

	modifyArray(a, SIZE);

	printf("Os valores do array modificado são:\n");

	for (i = 0; i < SIZE; i++)
	{
		printf("%3d",a[i]);
	}

	printf("“por valor: O valor de a[3] é %d\n",a[3]);

	modifyElement(a[3]);

	printf("O valor de a[3] é %d\n",a[3]);

	return 0;
}