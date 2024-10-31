#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubbleSort(int arr[], int n) 
{
    int i,j;

    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) 
{
    int key, j,i;
    
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) 
{
    int min_idx;
    int i;
    int j;

    for (i = 0; i < n - 1; i++) 
    {
        min_idx = i;
        for (j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[min_idx]) 
            {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// Merge Sort
void merge(int arr[], int l, int m, int r) 
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        } 

        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) 
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Quick Sort
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = (low - 1);
    int j;

    for (j = low; j <= high - 1; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Heap Sort
void heapify(int arr[], int n, int i) 
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (largest != i) 
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) 
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (i = n - 1; i > 0; i--) 
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Função para imprimir o array
void printArray(int arr[], int n) 
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    (void)argv[argc];

    system("clear");

    int tamanho;
    int escolha;
    int i;

    printf("Digite o tamanho do array (entre 100 e 100000): ");
    scanf("%d", &tamanho);

    if (tamanho < 100 || tamanho > 100000) 
    {
        printf("Tamanho inválido.\n");
        return 1;
    }
    printf("\n");

    int arr[tamanho];
    srand(time(NULL));

    for (i = 0; i < tamanho; i++) 
    {
        arr[i] = rand() % 1000; // Números aleatórios entre 0 e 999
    }

    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Heap Sort\n");
    printf("Escolha o algoritmo de ordenação:");
    scanf("%d", &escolha);

    switch (escolha) 
    {
        case 1:
            bubbleSort(arr, tamanho);
            printf("\nBubble Sort:\n");
            printArray(arr, tamanho);
            break;
        case 2:
            insertionSort(arr, tamanho);
            printf("\nInsertion Sort:\n");
            printArray(arr, tamanho);
            break;
        case 3:
            selectionSort(arr, tamanho);
            printf("\nSelection Sort:\n");
            printArray(arr, tamanho);
            break;
        case 4:
            mergeSort(arr, 0, tamanho - 1);
            printf("\nMerge Sort:\n");
            printArray(arr, tamanho);
            break;
        case 5:
            quickSort(arr, 0, tamanho - 1);
            printf("\nQuick Sort:\n");
            printArray(arr, tamanho);
            break;
        case 6:
            heapSort(arr, tamanho);
            printf("\nHeap Sort:\n");
            printArray(arr, tamanho);
            break;
        default:
            printf("Escolha inválida.\n");
            break;
    }
    return 0;
}