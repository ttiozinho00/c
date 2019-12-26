#include <stdlib.h>
#include <stdio.h>

long fibonacci(long n);

long fibonacci(long n)
{
	if ((n==0) | (n==1))
	{
		return n;
	}

	else
	{
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	long result;
	long num;

	printf("informe o valor:");
	scanf("%ld",&num);

	result=fibonacci(num);

	printf("\n");
	printf("Fibonacci(%ld) = %ld\n",num,result);

	return 0;
}