#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	int potencia;
	int i;
	int x;
	int y;

	potencia = 1;
	i = 1;

	printf("Informe o valor de x:");
	scanf("%d",&x);

	printf("Informe o valor de y:");
	scanf("%d",&y);

	while(i <= y)
	{
		potencia *= x;
		++i;
	}

	printf("\n");
	printf("%d\n",potencia);
	return 0;
}