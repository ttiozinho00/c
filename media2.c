#include <stdio.h>
#include <stdlib.h>


// Função para calcular a média
float calcularMedia(float PT, float R) {
    return ((PT * 0.6) + (R * 0.4));
}

int main(int argc, char const *argv[])
{
    system("clear");

    (void)argv[argc];

    float PT1, PT2, R1, R2;
    float N1, N2;

    // Entrada dos valores de PT1, PT2, R1 e R2
    printf("Digite o valor de PT1: ");
    scanf("%f", &PT1);
    printf("Digite o valor de R1: ");
    scanf("%f", &R1);
    printf("Digite o valor de PT2: ");
    scanf("%f", &PT2);
    printf("Digite o valor de R2: ");
    scanf("%f", &R2);

    // Cálculo das médias N1 e N2
    N1 = calcularMedia(PT1, R1);
    N2 = calcularMedia(PT2, R2);

    // Exibição dos resultados
    printf("A média N1 é: %.2f\n", N1);
    printf("A média N2 é: %.2f\n", N2);

    return 0;
}
