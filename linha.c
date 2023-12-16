#include <stdio.h>
#include <stdlib.h>

void imprime_linha()
{
    printf("\n--------------------------\n");
}

int main(int argc, char const *argv[])
{
    (void)argv[argc];

    imprime_linha();

    int *variavel;  

    variavel = (int *)malloc(sizeof(int)); 

    if (variavel == NULL)
    {
        fprintf(stderr, "Failed to allocate memory\n");
        return 1;  
    }

    *variavel = 123; 

    printf("%d\n", *variavel);

    free(variavel);  

    return 0;
}
