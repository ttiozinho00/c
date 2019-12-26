#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	int n;

	printf("Informe o valor:");
	scanf("%d",&n);

	if ((n >=1) & (n <= 9))
	{
		printf("\n");
		printf("O valor está na faixa permitida\n");
	}

	else
	{
		printf("\n");
		printf("O valor não está na faixa permitida\n");
	}

	return 0;
}