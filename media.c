#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argv=argv;
	argc=argc;

	int n1;
	int n2;
	int n3;
	int n4;
	float media;

	printf("Informe a primeira nota:");
	scanf("%d",&n1);

	printf("Informe a segunda nota:");
	scanf("%d",&n2);

	printf("Informe a terceira nota:");
	scanf("%d",&n3);

	printf("Informe a quarta nota:");
	scanf("%d",&n4);

	media = (n1+n2+n3+n4)/4;

	printf("\n");
	printf("%.2f\n",media);

	if (media >= 7)
	{
		printf("\n");
		printf("Aprovado!");
		printf("\n");
	}

	else
	{
		printf("\n");
		printf("reprovado!");
		printf("\n");
	}

	return 0;
}