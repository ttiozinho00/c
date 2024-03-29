#include <stdlib.h>
#include <stdio.h>

void selection_sort(int vetor[], int max) {
    int min;
    int aux;
    int i, j;

    for (i = 0; i < (max - 1); i++) 
    {
        min = i;
        for (j = i + 1; j < max; j++) 
        {
            if (vetor[j] < vetor[min]) 
            {
                min = j;
            }
        }

        if (i != min) 
        {
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }

    for (i = 0; i < max; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    system("cls || clear");

    argc = argc;
    argv = argv;

    int max;
    int i;

    printf("Informe o valor: ");
    scanf("%d", &max);

    int vetor[max];

    for (i = 0; i < max; i++) 
    {
        scanf("%d", &vetor[i]);
    }

    selection_sort(vetor, max);
    return 0;
}
