#include <stdlib.h>
#include <stdio.h>

long fatorial(long num);

long fatorial(long num)
{
	if (num <= 1)
	{
		return 1;
	}

	else
	{
		return(num * fatorial(num - 1));
	}
}

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	int i;

	for (i = 0; i <=10; i++)
	{
	 	printf("%2d! = %ld\n",i,fatorial(i));
	} 
	return 0;
}