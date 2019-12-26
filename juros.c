#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argv=argv;
	argc=argc;

	double principal;
	double valor;
	double taxa;
	int ano;

	principal = 1000.0;
	taxa = 0.05;

	printf("%4s%21s\n","ano","Valor na conta");

	for ( ano = 1; ano <= 10; ano++)
	{
		valor = principal * pow(1.0 + taxa,ano);

		printf("%4d%21.2f\n",ano,valor);
	}


	return 0;
}