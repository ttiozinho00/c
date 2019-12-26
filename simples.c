#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	float mult;
	float soma;
	float div;
	float sub;
	int a;
	int b;

	mult = 0;
	soma = 0;
	div = 0;
	sub = 0;
	a = 0;
	b = 0;

	soma = a+b;
	mult = a*b;
	div = a/b;
	sub = a-b;

	printf("Informe o primeiro valor:");
	scanf("%d",&a);

	printf("Informe o segundo valor:");
	scanf("%d",&b);

	printf("\n");
	printf("A soma eh:%.f\n",soma);
	printf("A subtração eh:%.f\n",sub);
	printf("A divisão eh:%.f\n",div);
	printf("A multiplicação eh:%.f\n",mult);

	return 0;
}