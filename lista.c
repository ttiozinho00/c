#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	int n[10] = { 32, 27, 64, 18, 95, 14, 90, 70, 60, 37 };
	int i;

	printf("%s%13s\n", "Elemento","Valor");

	for ( i = 0; i <= 10; i++)
	{
		printf("%7d%13d\n",i,n[i]);
	}

	return 0;
}