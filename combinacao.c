#include <stdlib.h>
#include <stdio.h>

/** 
 * Função para calcular o fatorial de um número
 * Argumentos:
 *   - num: número inteiro para o qual o fatorial será calculado
 * Retorno:
 *   - O fatorial de num como um valor unsigned long long
 */
unsigned long long fatorial(int num) 
{
    unsigned long long fat = 1; // Inicializa o fatorial como 1 */
    while (num > 1) 
    {
        fat *= num; /* Multiplica o fatorial pelo número atual */
        num--;      /* Decrementa o número */
    }
    return fat; /* Retorna o fatorial calculado */
}

/** 
 * Função para calcular a combinação nCr
 * Argumentos:
 *   - n: valor de n
 *   - r: valor de r
 * Retorno:
 *   - O valor de nCr como um valor unsigned long long
 */
unsigned long long combinacao(int n, int r) 
{
    return fatorial(n) / (fatorial(r) * fatorial(n - r)); /* Retorna o resultado da combinação */
}

int main(int argc, char const *argv[])
{
    (void)argv[argc]; /* Evita o warning "unused parameter" do compilador */

    system("clear"); /* Limpa a tela do terminal */

    int n, r; /* Declaração das variáveis para armazenar n e r */
    printf("Digite o valor de n: "); /* Solicita ao usuário o valor de n */
    scanf("%d", &n); /* Lê o valor de n fornecido pelo usuário */
    printf("Digite o valor de r: "); /* Solicita ao usuário o valor de r */
    scanf("%d", &r); /* Lê o valor de r fornecido pelo usuário */
    
    if (n < r) /* Verifica se n é menor que r */ 
    {
        printf("Erro: n deve ser maior ou igual a r.\n"); /* Exibe uma mensagem de erro se n for menor que r */
        return 1; /* Retorna 1 para indicar erro */
    }
    
    unsigned long long resultado = combinacao(n, r); /* Calcula a combinação nCr */
    printf("%dC%d = %llu\n", n, r, resultado); /* Exibe o resultado da combinação */

    return 0; // Retorna 0 para indicar sucesso
}
