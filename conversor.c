#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <locale.h>

void convertToUppercase(char *sPtr);

void convertToUppercase(char *sPtr)
{
	while(*sPtr != '\0')
	{
		if (islower(*sPtr))
		{
			*sPtr = toupper(*sPtr);
		}
		++sPtr;
	}
}

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	char string[] = "caracteres e R$32,98";

	printf("A string antes da conversão é: %s",string);
	convertToUppercase( string );

	printf("\n");
	printf("A string após da conversão é: %s",string);

	return 0;
}