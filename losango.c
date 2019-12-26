#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argv=argv;
	argc=argc;

	int lado1;
	int lado2;
	float area;

	printf("Informe a diagonal maior: ");
	scanf("%d",&lado1);

	printf("Informe a diagonal menor: ");
	scanf("%d",&lado2);

	area = (lado1*lado2)/2;

	printf("%.f\n",area);

	return 0;
}