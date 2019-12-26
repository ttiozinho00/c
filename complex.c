#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) 
{
	system("cls");

	argc=argc;
	argv=argv;

    unsigned int i;

    printf("argc=%d\n", argc);

    if (argc != 15) 
    {
        fputs("erro: precisa de 4 argumentos\n", stderr);
        return 0;
    }

    for (i = 0; i < 4; i++)
    {
        puts(argv[i]);
    }

    printf("%.0f\n", pow(2,10));

    return 0;
}
