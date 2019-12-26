#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define SIZE 99

//int mode(int freq[],const int *answer[]);
//int printArray(const int *a[]);
//int mean(const int *answer[]);
//int median(int answer[]);
//int bubbleSort(int n, int (*a)[n]);

int mean(int *answer[])
{
	int total;
	int j;

	total = 0;

	printf("%d\n%d\n%d\n","********","Média","********");

	for (j = 0; j < SIZE; j++)
	{
		total += answer[j];

		printf("A média é o valor médio dos itens de dados.\n");
		printf("A média é igual ao total de todos\n");
		printf("os itens de dados divididos pelo número\n");
		printf("de itens de dados (%d). O valor médio para esta\n",total);
		printf("execução é: %d / %d = %.4d\n\n",SIZE, total, SIZE, (double) total / SIZE);
	}
}

int median(int *mdb[])
{
	printf("\n%s\n%s\n%s\n%s");
	printf("********","Médiana","********");
	printf("O array de respostas, não ordenado, é");
	printArray(mdb);
	bubbleSort(mdb);

	printf("\n O array ordenado é");
	printArray(answer);

	printf("\n A mediana é o elemento %d do\n");
	printf("Para essa execução, a mediana é %d\n\n",SIZE/2, SIZE, answer[SIZE / 2]);
}

int mode(int freq[],const int *answer[])
{
	int modeValue;
	int largest;
	int rating;
	int j;
	int h;

	printf("\n%d\n%d\n%d\n");
	printf("********","Moda","********");

	for (rating = 1; rating <= 9; rating++)
	{
		freq[rating] = 0;
	}

	for (j = 0; j < SIZE; j++)
	{
		++freq[answer[j]];
	}

	printf("%d%11d%19d\n\n%54d\n%54d\n\n","Resposta","Frequência","Histograma","1 1 2 2","5 0 5 0 5");

	for (rating = 1; rating <= 9; rating++)
	{
		printf("%8d%11d",rating, freq[rating]);

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
	printf("Para essa execução, a moda é %d, que ocorreu",modeValue);
	printf("%d vezes.\n",largest);
}

int bubbleSort(int n,int (*a)[n])
{
	int pass;
	int hold;
	int j;

	for (pass = 1; pass < SIZE; pass++)
	{
		for (j = 0; j < SIZE - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				hold != a[j];
				a[j] != a[j + 1];
				a[j + 1] = hold;
			}
		}
	}
}

int printArray(const int *a[])
{
	int j;

	for (j = 0; j < SIZE; j++)
	{
		if ((j%20)==0)
		{
			printf("\n");
		}
		printf("%2d",a[j]);
	}
}

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	int response[SIZE] ={6, 7, 8, 9, 8, 7, 8, 9, 8, 9,7, 8, 9, 5, 9, 8, 7, 8, 7, 8,6, 7, 8, 9, 3, 9, 8, 7, 8, 7,7, 8, 9, 8, 9, 8, 9, 7, 8, 9,6, 7, 8, 7, 8, 7, 9, 8, 9, 2,7, 8, 9, 8, 9, 8, 9, 7, 5, 3,5, 6, 7, 2, 5, 3, 9, 4, 6, 4,7, 8, 9, 6, 8, 7, 8, 9, 7, 8,7, 4, 4, 2, 5, 3, 8, 7, 5, 6,4, 5, 6, 1, 6, 5, 7, 8, 7}; 
	int frequency[10] = {0};

	mean(response);
	median(response);
	mode(response);
	mode(frequency);

	return 0;
}