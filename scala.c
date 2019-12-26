#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	int i;

	for ( i = 0; i <= 20+1; i++)
	{
		printf("%10d\n",1+(rand()%20));
	}

	if ((i%5)==0)
	{
		printf("\n");
	}

	return 0;
}