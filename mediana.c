#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define SIZE 99

void mean(int *answer);
void median(int *mdb);
void mode(int freq[], const int *answer);
void bubbleSort(int n, int a[n]);
void printArray(const int a[]);



int main(int argc, char const *argv[])
{
    system("cls");
    setlocale(LC_ALL, "");

    argc = argc;
    argv = argv;
  
    int *response = malloc(SIZE * sizeof(int));
    if (response == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    int frequency[10] = {0};

    mean(response);
    median(response);
    mode(frequency, response);

  
    free(response);

    return 0;
}

void mean(int *answer)
{
    int total = 0;
    int j;

    printf("%s\n%s\n%s\n", "********", "Média", "********");

    for (j = 0; j < SIZE; j++)
    {
        total += answer[j];
    }

    printf("A média é o valor médio dos itens de dados.\n");
    printf("A média é igual ao total de todos\n");
    printf("os itens de dados divididos pelo número\n");
    printf("de itens de dados (%d). O valor médio para esta\n", SIZE);
    printf("execução é: %d / %d = %.4f\n\n", total, SIZE, (double)total / SIZE);
}

void median(int *mdb)
{
    printf("\n%s\n%s\n%s\n", "********", "Mediana", "********");
    printf("O array de respostas, não ordenado, é");
    printArray(mdb);
    bubbleSort(SIZE, mdb);

    printf("\n O array ordenado é");
    printArray(mdb);

    printf("\n A mediana é o elemento %d do\n", SIZE / 2);
    printf("Para essa execução, a mediana é %d\n\n", mdb[SIZE / 2]);
}

void mode(int freq[], const int *answer)
{
    int modeValue = 0;
    int largest = 0;
    int rating;
    int j;
    int h;

    printf("\n%s\n%s\n%s\n", "********", "Moda", "********");

    for (rating = 1; rating <= 9; rating++)
    {
        freq[rating] = 0;
    }

    for (j = 0; j < SIZE; j++)
    {
        ++freq[answer[j]];
    }

    printf("%s%11s%19s\n\n%54s\n%54s\n\n", "Resposta", "Frequência", "Histograma", "1 1 2 2", "5 0 5 0 5");

    for (rating = 1; rating <= 9; rating++)
    {
        printf("%8d%11d", rating, freq[rating]);

        if (freq[rating] > largest)
        {
            largest = freq[rating];
            modeValue = rating;
        }

        for (h = 1; h <= freq[rating]; h++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("A moda é o valor mais frequente.\n");
    printf("Para essa execução, a moda é %d, que ocorreu", modeValue);
    printf(" %d vezes.\n", largest);
}

void bubbleSort(int n, int a[n])
{
    int pass;
    int hold;
    int j;

    for (pass = 1; pass < n; pass++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                hold = a[j];
                a[j] = a[j + 1];
                a[j + 1] = hold;
            }
        }
    }
}

void printArray(const int a[])
{
    int j;

    for (j = 0; j < SIZE; j++)
    {
        if ((j % 20) == 0)
        {
            printf("\n");
        }
        printf("%3d", a[j]);
    }
    printf("\n");
}