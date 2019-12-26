/*221*/

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void printCharacters(const char *sPtr);

void printCharacters( const char *sPtr )
 {
	for ( ; *sPtr != '\0'; sPtr++ ) 
	{
	 	printf("%c",*sPtr);
 	} 
 }

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	char string[] = "imprime caracteres de uma string";

	printf( "A string é:\n");
	printCharacters(string);
 	printf("\n");
 	  
	return 0;
}