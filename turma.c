#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
	system("cls");

	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	int contador;
	int media;
	int total;
	int nota;

	total = 0;
	contador = 1;

	while(contador <= 10)
	{
		printf("Informe a nota:");
		scanf("%d",&nota);

		total = total + nota;
		contador = contador + 1;
	}

	media = total/10;

	printf("\n");
	printf("A média da turma é %d\n",media);

	return 0;
}