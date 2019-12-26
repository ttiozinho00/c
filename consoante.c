#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argv=argv;
	argc=argc;

	char consoante;
	char vogal;

	vogal = 'a';

	printf("Informe uma consoante:");
	scanf("%c",&consoante);

	printf("Vogal:%c consoante:%c \n",vogal,consoante);

	return 0;
}