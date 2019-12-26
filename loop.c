#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	int x;

	for (x = 0;x < 10+1; x++)
	{
		if (x == 5)
		{
			break;
		}

		printf("%d\n",x);
	}	

	printf("\nSaiu do loop em x == %d\n",x);

	return 0;
}