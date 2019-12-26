#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argv=argv;
	argc=argc;

	float porcentagem_candidato_a;
	float porcentagem_candidato_b;
	float porcentagem_brancos;
	float porcentagem_nulos;
	int candidato_a;
	int candidato_b;
	int total_votos;
	int brancos;
	int nulos;
	int voto;

	candidato_a = 0;
	candidato_b = 0;
	total_votos = 0;
	brancos = 0;
	nulos = 0;

	do
	{
		system("cls");

		printf("Escolha o seu candidato ou tecle zero para encerrar\n\n");

		printf("1 -> Candidato A\n");
		printf("2 -> Candidato B\n");
		printf("3 -> Branco\n");

		printf("\n");
		printf("Qualquer Número diferente séra anulado!!\n");
		printf("Digite o seu voto:");
		scanf("%d",&voto);

		system("cls");

		switch (voto)
		{
			case 0:
				printf("Votação encerrada!!\n");
				break;

			case 1:
				candidato_a = candidato_a + 1;
				break;

			case 2:
				candidato_b = candidato_b + 1;
				break;	

			case 3:
				brancos = brancos + 1;
				break;

			default:
				nulos = nulos + 1;
				break;		
		}
	}while(voto != 0);

	total_votos = candidato_a + candidato_b + brancos + nulos;

	if (total_votos > 0)
	{
		porcentagem_candidato_a = (candidato_a * 100.0) / total_votos; 
		porcentagem_candidato_b = (candidato_b * 100.0) / total_votos;
		porcentagem_brancos = (brancos * 100.0) / total_votos;
		porcentagem_nulos = (nulos * 100.0) / total_votos;

		printf("\n");
		printf("Total de votos:%d\n",voto);
		printf("Candidato A:%d votos %.f do total!!\n",candidato_a,porcentagem_candidato_a);
		printf("Candidato B:%d votos %.f do total!!\n",candidato_b,porcentagem_candidato_b);
		printf("Brancos:%d votos %.f do total!!\n",brancos,porcentagem_brancos);
		printf("Nulos:%d votos %.f do total!!\n",nulos,porcentagem_nulos);
	}

	return 0;
}	