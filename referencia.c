#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void cubeByReference(int *nPtr); 

void cubeByReference(int *nPtr)
{
	*nPtr = *nPtr * *nPtr * *nPtr; 
} 

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	int number = 5; 

 	printf("O valor original do n�mero �: %d", number);
	cubeByReference( &number );

	printf( "\nO novo valor do n�mero �: %d\n", number);
 	return 0; 


	return 0;
}