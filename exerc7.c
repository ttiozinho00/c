/*

Execução: gcc -o exerc7 exerc7.c -pedantic -Wextra -Wall

*/

#include <stdio.h> /* printf(), scanf()*/
#include <string.h> /*strcat() */

int main (int argc, char *argv[])
{
    char A[1000]="Abra a porta para entrar para poder descansar calmamente";
    char velhastr[100]="para";
    char novastr[100]="e tente";
    char resultado[1000] = "";
    char *tmp;
    int len;
    char *strAuxiliar= A;
    char *res = resultado;

    argc = argc;
	argv = argv;

    while(1) 
    {
        tmp = strstr(strAuxiliar, velhastr);

        if(tmp == NULL)
        {
            break;
        }

        len = tmp - strAuxiliar;  

        tmp = tmp + strlen(velhastr);  

        strncpy(res, strAuxiliar, len); // cópias até n caracteres da cadeia de caracteres apontada, por src para destino
        strcat(res, novastr); 

        res += len + strlen(novastr);
        strAuxiliar = strAuxiliar + len + strlen(velhastr); 
    }

    if(!tmp)
    {
        strcat(resultado, strAuxiliar);
    }

    printf("Resultado: %s", resultado);
    return(0);
}