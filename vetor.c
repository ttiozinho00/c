#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argv=argv;
	argc=argc;

	int posisao;
	int numero;
	int vetor[] = {1,2,4,5,6};
	bool achou = false;

	posisao = 0;

	printf("informe o valor que deseja proucurar:");
	scanf("%d",&numero);

	for (posisao = 0; posisao < 5; posisao++)
	{
		if (vetor[posisao] == numero)
		{
			printf("\n");
			printf("Encontrado na posição:%d",posisao);
			achou = true;
		}

		if (achou)
		{
			printf("O número não está no vetor\n");
		}
	}

	return 0;
}