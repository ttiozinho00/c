#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	char operador;
	float resultado;
	float n1;
	float n2;

	printf("Digite o primeiro numero:");
	scanf ("%f",&n1);

	printf("Digite o segundo numero:");
	scanf ("%f",&n2);

	printf("Digite o operador:");
	scanf ("%s",&operador);

	getchar();

	if (operador=='+') 
	{
		resultado=n1+n2;    
		printf ("\n O resultado e: %.f",resultado);
	}   	
  
	else if (operador=='-') 
	{
		resultado=n1-n2;
		printf ("\n O resultado e: %.f",resultado);
		
	}


	else if (operador=='/') 
	{	
		resultado=n1/n2;
		printf ("\n O resultado e: %.f",resultado);
	}
	

	else if (operador=='*') 
	{	
		resultado=n1*n2;
		printf ("\n O resultado e: %.f",resultado);
		 
	}  

	getchar();
	return 0;
}