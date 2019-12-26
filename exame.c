#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	int reprovados;
	int resultado;
	int aprovados;
	int aluno;

	aprovados = 0;
	reprovados = 0;
	aluno = 1;

	while(aluno <= 10)
	{
		printf("Forneça resultado ( 1=aprovado,2=reprovado):");
		scanf("%d",&resultado);

		if (resultado == 1)
		{
			aprovados = aprovados + 1;
		}

		else
		{
			reprovados = reprovados + 1;
		}
		aluno = aluno + 1;
	}	

	printf("\n");
	printf("Aprovados %d\n",aprovados);
	printf("Reprovados %d\n",reprovados);

	if (aprovados > 8)
	{
		printf("\n");
		printf("Bouns ao Instrutor!\n");
	}

	return 0;
}