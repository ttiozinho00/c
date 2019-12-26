#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argv=argv;
	argc=argc;

	int soma;
	int x;

	soma = 0;
	x = 1;

	while(x <= 10)
	{
		soma += x;
		++x;
	}

	printf("A soma é:%d\n",soma);

	return 0;
}