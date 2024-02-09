#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double calcularEa(double Ra, double Rb) 
{
    double Ea = 1 / (1 + 10 * (Rb - Ra) * 1400);
    return Ea;
}

double calcularEb(double Ra, double Rb) 
{
    double Eb = 1 / (1 + 10 * (Ra - Rb) * 1400);
    return Eb;
}

int main(int argc, char const *argv[])
{
    (void)argv[argc];

    double Ra, Rb;

    system("clear");

    printf("Digite o valor de Ra: ");
    scanf("%lf", &Ra);

    printf("Digite o valor de Rb: ");
    scanf("%lf", &Rb);

    // Calculando Ea e Eb
    double Ea = calcularEa(Ra, Rb);
    double Eb = calcularEb(Rb, Ra);

    // Exibindo os resultados
    printf("Ea = %lf\n", Ea);
    printf("Eb = %lf\n", Eb);
    return 0;
}