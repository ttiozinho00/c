#include <stdlib.h>
#include <stdio.h>

int square(int y);

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	int x;

	for (x = 0;x <= 10+1; x++)
	{
		printf("%d ",square(x));
	}
	printf("\n");

	return 0;
}

int square(int y)
{
	return y * y;
}