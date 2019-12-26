#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	int cont;
	unsigned seed;

	printf("Digite a semente:");
	scanf("%u",&seed);

	for (cont = 0; cont <= 10+1;cont++)
	{
		printf("%10d",1 + (rand()%6));

		if ((cont%5)==0)
		{
			printf("\n");
		}
	}

	return 0;
}