#include <stdio.h>
#include <stdlib.h>

int string_count(char str[]);

int string_count(char str[]) 
{
    int i = 0;

    while (str[i] != '\0') 
    {
        i++;
    }

    return i;
}

int main()
{
    system("cls");

    char str[100];
    int contador;

    printf("Digite uma palavra: ");
    fgets(str, sizeof(str), stdin);


    contador = string_count(str);

    printf("A string possui %d caracteres.\n", contador);

    system("pause");
    return 0;
}
