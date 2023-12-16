#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	float *v;
	int i; 
    int num_componentes;
  
  	num_componentes = 0;

    printf("Informe o numero de componentes do vetor:");
     scanf("%d", &num_componentes);

    v = (float *) malloc(num_componentes * sizeof(float));
  
  	for (i = 0; i < num_componentes; i++)
  	{
    	printf("\nDigite o valor para a posicao %d do vetor: ", i+1);
    	scanf("%f",&v[i]);
  	}

  	printf("\n");
  	for (i = 0;i < num_componentes; i++)
  	{
    	printf("%.2f\n",v[i]);
  	}
  
  	free(v);
  
  	getchar();

	return 0;
}