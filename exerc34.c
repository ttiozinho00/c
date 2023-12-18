/*
Execução: gcc -o exerc34.exe exerc34.c -pedantic -Wextra -Wall
*/ 


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i = 0;
    char comando[17]= "taskkill /f /im ";//Comando disponivel pelo console do windows

    if(argc >= 2)
    {   
        strcat(comando, argv[1]);//concateno a string inicial com valor passado pelo usuario
        system(comando);
    }
    
    else
    {
        printf("Argumento vazio.\n");
    }
    return 0;
}