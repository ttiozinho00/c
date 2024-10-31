#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	system("cls"); // Limpa o console

    // Variáveis para contagem de votos
    int candidato_a = 0;
    int candidato_b = 0;
    int brancos = 0;
    int nulos = 0;
    int total_votos = 0;
    int voto;

    do
    {
        system("cls"); // Limpa o console

        printf("Escolha o seu candidato ou tecle zero para encerrar\n\n");
        printf("1 -> Candidato A\n");
        printf("2 -> Candidato B\n");
        printf("3 -> Branco\n\n");
        printf("Digite o seu voto: ");
        scanf("%d", &voto);

        switch (voto)
        {
        case 0:
            printf("Votação encerrada!!\n");
            break;
        case 1:
            candidato_a++;
            break;
        case 2:
            candidato_b++;
            break;
        case 3:
            brancos++;
            break;
        default:
            nulos++;
            break;
        }

        total_votos++; // Incrementa o total de votos

    } while (voto != 0);

    if (total_votos > 0)
    {
        // Cálculo das porcentagens
        float porcentagem_candidato_a = (candidato_a * 100.0) / total_votos;
        float porcentagem_candidato_b = (candidato_b * 100.0) / total_votos;
        float porcentagem_brancos = (brancos * 100.0) / total_votos;
        float porcentagem_nulos = (nulos * 100.0) / total_votos;

        // Exibição dos resultados
        printf("\nTotal de votos: %d\n", total_votos);
        printf("Candidato A: %d votos %.2f%% do total\n", candidato_a, porcentagem_candidato_a);
        printf("Candidato B: %d votos %.2f%% do total\n", candidato_b, porcentagem_candidato_b);
        printf("Brancos: %d votos %.2f%% do total\n", brancos, porcentagem_brancos);
        printf("Nulos: %d votos %.2f%% do total\n", nulos, porcentagem_nulos);
    }
	return 0;
}