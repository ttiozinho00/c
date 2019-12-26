#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	int total;
	int x;
	int y;

	total = 0;
	x = 1;

	while(x <= 10)
	{
		printf("%d\n",y);
		y = x*x;
		total += y;
		++x;
	}

	printf("\n");
	printf("%d\n",total);

	return 0;
}