#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	int x;

	for (x = 0;x < 10+1; x++)
	{
		if (x == 5)
		{
			continue;
		}

		printf("%d\n",x);
	}	

	printf("\nUsou continue para pular a exibição do valor 5\n");

	return 0;
}