#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    system("cls");
    setlocale(LC_ALL, "");

    argc = argc;
    argv = argv;

    int *aptr;
    int a;

    a = 7;
    aptr = &a;

    printf("O endereço de a é %p\n", (void *)&a);
    printf("O valor de aPtr é %p\n", (void *)aptr);

    printf("O valor armazenado no endereço de a é %d\n", a);
    printf("O valor apontado por aPtr é %d\n", *aptr);

    printf("\n\nMostrando que * e & são complementos um do outro\n&*aPtr = %p\n", (void *)&(*aptr));

    return 0;
}
