#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	int qtd_anos_bi;
	int ano_atual;
	int dias;

	printf("Informe o ano atual:");
	scanf("%d",&ano_atual);

	qtd_anos_bi = ano_atual /4;
	dias = (ano_atual - 1) * 365 + qtd_anos_bi; 

	printf("Já se passaram:%d dias desde 01/01/0001\n\n",dias);

	return 0;
}