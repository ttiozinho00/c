#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int calc(float n1, float n2)
{
	float result;

	result = n1*n2;

	return (result); 
}

int main(int argc, char const *argv[])
{

	argv=argv;
	argc=argc;

	float result;
	int a;
	int b;

	printf("Informe o primeiro angulo:");
	scanf("%d",&a);

	printf("Informe o segundo angulo:");
	scanf("%d",&b);

	result = pow(a,b)/2;

	printf("\n");
	printf("%.f\n",result);

	getchar();
	return 0;
}