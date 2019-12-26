#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int fibonacci(int posisao)
{
	if (posisao == 1)
	{
		return 0;
	}

	else if (posisao == 2)
	{
		return 1;
	}

	return fibonacci(posisao -1) + fibonacci(posisao -2);
}


int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argv=argv;
	argc=argc;

	int fibonacci[1];
	int numero; 
	int i;

	printf("Infome a sequência:");
	scanf("%d",&numero);

	for (i = 0; i < numero; i++)
	{
		printf("%d",fibonacci[numero]);
	}

	return 0;
}