#include <stdio.h>

// Função para calcular o fatorial de um número
unsigned long long fatorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * fatorial(num - 1);
    }
}

// Função para calcular combinações C(n, p)
unsigned long long combinacao(int n, int p) {
    if (p < 0 || p > n) {
        return 0;  // C(n, p) é indefinido para p fora do intervalo [0, n]
    }

    return fatorial(n) / (fatorial(p) * fatorial(n - p));
}

int main() {
    int n, p;

    // Obter valores de n e p do usuário
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("Digite o valor de p: ");
    scanf("%d", &p);

    // Calcular e exibir C(n, p)
    printf("C(%d, %d) = %llu\n", n, p, combinacao(n, p));

    return 0;
}
