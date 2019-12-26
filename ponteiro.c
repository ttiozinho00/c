#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char const *argv[])
{
	system("cls");

	argv=argv;
	argc=argc;

	int a;
	int b;
	float calc;
	float raiz;	

	printf("Informe o primeiro  valor:");
	scanf("%d",&a);

	printf("Informe o segundo valor:");
	scanf("%d",&b);

	calc = (pow(2,a)+b);
	raiz = sqrt(calc);

	printf("\n");
	printf("%.2f\n",calc);

	printf("\n");
	printf("%.2f\n",raiz);

	return 0;
}