#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	int i;
	int j;
	int x;
	int y;

	printf("Informe dois valores no intervalo de 1-20:");
	scanf("%d %d",&x,&y);

	for (i = 1; i <= y; i++)
	{
		for (j = 1; j < x; j++)
		{
			printf("@");
		}
		printf("\n");
	}

	return 0;
}