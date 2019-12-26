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

 	printf("O valor original do número é: %d", number);
	cubeByReference( &number );

	printf( "\nO novo valor do número é: %d\n", number);
 	return 0; 


	return 0;
}