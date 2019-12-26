#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argv=argv;
	argc=argc;

	int contador;

	contador = 1;

	while(contador <= 10)
	{
		printf("%s\n",contador % 2 ? "****":"+++++++");
		contador ++;
	}

	return 0;
}