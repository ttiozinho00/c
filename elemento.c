#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	int n[10];
	int i;

	for (i = 0; i < 10; i++)
	{
		n[i] = 0;
	}

	printf("%s%13s\n", "Elemento","Valor");

	for (int i = 0; i < 10; i++)
	{
		printf("%7d%13d\n",i,n[i]);
	}

	return 0;
}