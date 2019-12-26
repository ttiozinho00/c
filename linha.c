#include <stdio.h>
#include <stdlib.h>

void imprime_linha()
{
	printf("\n--------------------------\n");
}

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	imprime_linha();

	int variavel = 123;

	variavel = malloc(sizeof(int));

	printf("%d\n",variavel);

	return 0;
}