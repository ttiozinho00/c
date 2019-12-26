#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int cubeByValue(int n);

int cubeByValue(int n)
{
	return n*n*n;
}

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	int num;

	num = 5;

	printf("O valor do numero original é:%d",num);

	num = cubeByValue(num);

	printf("\n");
	printf("O valor do numero novo é:%d",num);
	return 0;
}