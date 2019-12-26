#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argv=argv;
	argc=argc;

	int soma;
	int i;

	soma = 0;

	if (argc == 0)
	{
		printf("Sistema sem parametro: %s",argv[0]);
	}

	else
	{
		printf("Parametro do Sistema: %s",argv[0]);

		for (i = 0;i < argc;i++)
		{
			soma = soma + atoi(argv[i]);
			printf("Soma %d\n",soma);
		}
	}

	return 0;
}