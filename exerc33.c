/*

Execução: gcc -o exerc29.exe exerc29.c -pedantic -Wextra -Wall

*/

#include <stdio.h> /* printf() */
#include <stdlib.h> /* getenv(), NULL */
#include <string.h>

int main(int argc, char *argv[], char *env[])
{
    int i = 0;
    char *variavel;
    char *ret;
    char needle[20] = "c:\\Dev-cpp\\bin";
	/* Silenciar os parâmetros não utilizados argc e argv */
	argc = argc;
	argv = argv;

    variavel = getenv("PATH");
    ret = strstr(variavel, needle);

    if (ret!= NULL) 
    {
      printf("Variavel Dev-cpp: %s\n", ret);
    }

    else
    {
        system("setx /M path '%path%;C:\\Users\\user\\Downloads\\a-pdf-te' ");
    }
    variavel = getenv("PATH");
    printf("Variaveis : %s\n", variavel);
    return(0);
}

