#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	int numero;

	printf("Informe o valor:");
	scanf("%d",&numero);

	if (((numero % 5)==0) && ((numero % 3)==0))
	{
		printf("O numero � divisivel\n");
	}

	else
	{
		printf("O numero n�o � divisivel\n");	
	}

	return 0;
}