#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	int posisao;
	char nome;
	float altura;

	nome = 0;
	altura = 0;

	for (posisao = 0; posisao < 5; posisao++)
	{
		printf("%c %.f",nome,altura);
	}

	return 0;
}