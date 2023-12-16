#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <math.h>

int calculo(int n1, int n2)
{
	int resultado;
	resultado = n1*n2;
	return(resultado);
}


int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	int resultado;
	int V1;
	int V2;

  	printf("Digite o primeiro valor:");
  	scanf("%d", &V1);

  	printf("Digite o segundo valor:");
  	scanf("%d", &V2);

  	resultado = pow(V1,V2);

  	printf("Resultado = %d\n", resultado);

  	getchar();
	return 0;
}
