#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	float altura1;
	float altura2;
	float altura3;
	float media_altura;

	printf("Digite a altura da primeira pessoa: ");
	scanf("%f",&altura1);

	printf("Digite a altura da primeira pessoa: ");
	scanf("%f",&altura2);

	printf("Digite a altura da primeira pessoa: ");
	scanf("%f",&altura3);

	media_altura = (altura1 + altura2 + altura3) / 3;

	printf("A média das alturas é: %.f metros\n",floor(media_altura));
	printf("\n");

	return 0;
}