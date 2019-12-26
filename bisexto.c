#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	int mesfevereirobissexto;
	int anobissexto;
	int ano; 
	char mes[15];
 	
 	printf("Informe o mês:");
	scanf("%s",mes);

	printf("Informe o ano:");
	scanf("%d",&ano);
	 
	if ((ano%4)==0) 
	{
		anobissexto = 366;
		mesfevereirobissexto = 29;
	}
	 
	else 
	{
		anobissexto = 365;
		mesfevereirobissexto = 28;
	}
	 
	if (strcmp(mes,"janeiro") == 0)
	{
		printf("\n");
		printf("dias = 31\n");
		printf("dias no ano = %d\n",anobissexto);
	}
	 
	else if (strcmp(mes,"fevereiro") == 0)
	{
		printf("\n");
		printf("dias = %d\n",mesfevereirobissexto);
		printf("dias no ano = %d\n",anobissexto);
	}
	 
	else if (strcmp(mes,"março") == 0)
	{
		printf("\n");
		printf("dias = 31\n");
		printf("dias no ano = %d\n",anobissexto);
	}
	 
	else if (strcmp(mes,"abril") == 0)	
	{
		printf("\n");
		printf("dias = 30\n");
		printf("dias no ano = %d\n",anobissexto);
	}
	 
	else if (strcmp(mes,"maio") == 0)
	{
		printf("\n");
		printf("dias = 31\n");
		printf("dias no ano = %d\n",anobissexto);
	}
	 
	else if (strcmp(mes,"junho") == 0)
	{
		printf("\n");
		printf("dias = 30\n");
		printf("dias no ano = %d\n",anobissexto);
	}
	 
	else if (strcmp(mes,"julho") == 0)	
	{
		printf("\n");
		printf("dias = 31\n");
		printf("dias no ano = %d\n",anobissexto);
	}
	 
	else if (strcmp(mes,"agosto") == 0)
	{
		printf("\n");
		printf("dias = 31\n");
		printf("dias no ano = %d\n",anobissexto);
	}
	 
	else if (strcmp(mes,"setembro") == 0)
	{
		printf("\n");
		printf("dias = 30\n");
		printf("dias no ano = %d\n",anobissexto);
	}
	 
	else if (strcmp(mes,"outubro") == 0)
	{
		printf("\n");
		printf("dias = 31\n");
		printf("dias no ano = %d\n",anobissexto);
	}

	else if (strcmp(mes,"novemvro") == 0)
	{
		printf("\n");
		printf("dias = 30\n");
		printf("dias no ano = %d\n",anobissexto);
	}

	else if (strcmp(mes,"dezembro") == 0)
	{
		printf("\n");
		printf("dias = 31\n");
		printf("dias no ano = %d\n",anobissexto);
	}

	return 0;
}