#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	int *aptr;
	int a;

	a = 7;
	aptr = &a;

	printf("O endereço de a é %d\n","valor de aPtr é %d",&a,aptr);

	printf("O endereço de a é %d\n","valor de aPtr é %d",&a,*aptr);

	printf("\n\n Mostrando que * e & são complementos um","do outro\n &*aPtr = %d");

	return 0;
}