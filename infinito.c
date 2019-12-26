#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	int c;

	if ((c = getchar())!=EOF)
	{
		//main();
		printf("%c",c);
	}

	return 0;
}