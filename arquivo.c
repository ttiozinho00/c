#include <stdio.h>
#include <stdlib.h>

void print_pow(void);

int main(int argc, char const *argv[]) 
{
    system("cls");

    unsigned int i;

    printf("argc=%d\n", argc);

    if (argc != 4) 
    {
        fputs("error: need 3 arguments\n", stderr);
        return 1;
    }

    for (i = 0; i < 4; i++)
    {
        puts(argv[i]);
    }

    void print_pow();

    return 0;
}
