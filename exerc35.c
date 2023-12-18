/*

Execução: gcc -o exerc35.exe exerc35.c -pedantic -Wextra -Wall

*/

#include<stdio.h> /* printf(), scanf()*/

int PercorreVetor(int vet[], int i, int n, int contador)
{
	/* Verifica se a função abaixo foi concluida e retorna quantos valores impares tem.*/
	if (i == n)
	{
		return contador;
	}
		
	/* Verifica quais dos índices do vetor são impares, e conta quantos valores impares tem.*/
	if (i < n)
	{
		if (vet[i] % 2 != 0)
		{
			contador ++;
		}
		i++;
	}

	return PercorreVetor(vet, i, n, contador);
}
	
int main(int argc, char *argv[])
{
    int vet[20], i, n, contador;
	
	argc = argc;
	argv = argv;
	contador = 0;
	
	printf ("Informe o tamanho do vetor\n");
	scanf ("%d", &n);
	
	printf ("Informe os valores do vetor\n");
    for (i = 0; i < n; i ++)
    {
        scanf("%d", &vet[i]);
    }
	
	i = 0;
	contador = PercorreVetor(vet, i, n, contador);
	printf ("O vetor tem %d valores impares", contador);
	
	return 0;
}

