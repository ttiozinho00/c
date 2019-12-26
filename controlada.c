#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	int contador;

	contador = 1;

	while(contador <= 10)
	{
		printf("%d\n",contador);
		contador++;
	}

	return 0;
}