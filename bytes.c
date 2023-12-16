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

	printf("O número de bytes no array é %ld\n", sizeof(array));
	printf("O número de bytes retornados por getSize é %ld\n", getSize(array));

	return 0;
}

