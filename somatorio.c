#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	int numero;
	int soma;

	soma = 0;

	for (numero = 2; numero <= 100; numero++)
	{
		soma += numero;
	}

	printf("%d\n",soma);

	return 0;
}