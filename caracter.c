#include <stdio.h>
#include <stdlib.h>

int string_count(char str[]);

int string_count(char str[]) 
{
    int i;
    int j;

    i = 0;
    j = 0;

    while(str[i] = str[j])
    {
    	return i;
    }
}

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	char str[100];
 	int contador;
  
 	printf("Digite uma palavra: ");
 	gets(str);
  
 	contador = string_count(str);
  
 	printf("A string possui %d caracteres.n", contador);
  
 	system("pause");
 	return 0;
}
 