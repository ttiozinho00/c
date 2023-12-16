#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    system("cls || clear");
    setlocale(LC_ALL, NULL);

    argv=argv;
    argc=argc;

    int num;
    double result;
    char output[500];
    char *ret;
    
    for(num=970;num<=970;num++)
    {
        printf("Informe o valor:");
        scanf("%d", &num);
        
        result=pow(2,num);
        snprintf(output, 500, "%.500g", result);
        printf("DIGITOS: %d\n\n ",(int) strlen(output));

        if((ret=strstr(output,"666"))!=NULL)
        {
            printf("NÚMERO: %s\n\n\n", output);
            printf("LOCAL: %s\n\n\n", ret);
            printf("NUM: %d\n", num);
            printf("\n");
        }
        
        else
        {
            printf("Não apocalíptico\n");
            printf("\n");
        }
    }

    return 0;
}