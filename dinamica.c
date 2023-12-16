#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    system("cls");
    setlocale(LC_ALL, "");

    argc = argc;
    argv = argv;

    int *pt_a;  

    pt_a = (int*)malloc(sizeof(int));

    if (pt_a == NULL)
    {
        printf("Mem�ria insuficiente!\n");
        exit(1);
    }

    printf("Endere�o de pt_a: %p\n", (void*)pt_a); 

    *pt_a = 90;

    printf("Conte�do de pt_a: %d\n", *pt_a);
    free(pt_a);

    return 0;
}
