#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

size_t getSize(float *ptr);

size_t getSize(float *ptr)
{
	return sizeof(ptr);
}

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	float array[20];

	printf("O n�mero de bytes no array � %ld\n", sizeof(array));
	printf("O n�mero de bytes retornados por getSize � %ld\n", getSize(array));

	return 0;
}

