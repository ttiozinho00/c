#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	int coluna;
	int linha;

	linha = 10;

	while(linha >= 1)
	{
		coluna = 1;

		while(coluna <= 10)
		{
			printf("%s\n",linha % 2 ? "<":">");
			coluna ++;
		}

		linha --;
		printf("\n");
	}

	return 0;
}