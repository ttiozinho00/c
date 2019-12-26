#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	int *ptr_a;
	int pt_a;



	pt_a = malloc(sizeof(int));

	if (pt_a == NULL)
	{
		printf("Memória insuficiente!\n");
    	exit(1);
	}

	printf("Endereço de ptr_a: %d \n",  pt_a);

  	*ptr_a = 90;

  	printf("Conteúdo de ptr_a: %d\n", *ptr_a);  
  	free(ptr_a);

	return 0;
}