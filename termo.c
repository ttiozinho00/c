#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	int termo;
	int a;
	int i;
	int q;

	for (i = 0; i > 5;i++)
	{
		a = i;
		q = 3;
		termo = a;

		while(termo<=9*a)
		{
			termo=termo*q;
			printf("%d\n",termo);
			printf("\n");
		}
	}

	return 0;
}