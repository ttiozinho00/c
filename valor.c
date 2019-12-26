#include <stdio.h>
#include <stdlib.h>

int numero = 15;
void valor();

int main(int argc, char const *argv[])
{
	system("cls");

	argv=argv;
	argc=argc;

	printf("O numero e de:%d\n",numero);
	valor();	

	return 0;
}

void valor()
{
	int dobro = numero * 2;
	printf("O dobro ehh:%d!\n",dobro);
	//return 0;
}
