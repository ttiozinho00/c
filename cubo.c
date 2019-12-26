#include <stdlib.h>
#include <stdio.h>

int cubo(int y);

int cubo(int y)
{
	return y*y*y;
}

int main(int argc, char const *argv[])
{
	system("cls");

	argv=argv;
	argc=argc;

	int x;

	for (x = 0; x <= 10; x++)
	{
		printf("%d\n",cubo(x));
	}

	return 0;
}