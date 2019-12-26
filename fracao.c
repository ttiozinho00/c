#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argv=argv;
	argc=argc;

	float inteiro;
	float fracao;
	float partes;

	printf (" Digite o valor do inteiro:");
	scanf  ("%f",&inteiro);

	printf (" Digite a quantidade de partes:");
	scanf  ("%f",&partes);

	fracao=inteiro/partes;

	printf ("\n A fracao e: %f ",fracao);

	getch();

	return 0;
}