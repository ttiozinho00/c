#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	int desconto;
	int percelas;
	float total;
	int juros;
	int preco;

	desconto = 1.500;
	percelas = 10;
	juros = 50;
	preco = 20.000;

	total = ((preco+percelas)*juros) - desconto;

	printf("O valor é de:%.f\n",total);

	return 0;
}