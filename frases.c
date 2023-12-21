#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Função para gerar um número aleatório entre min e max*/
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

/* Função para gerar uma frase aleatória */
void gerarFrase() {
    // Partes da frase
    char *sujeito[] = {"O gato", "O cachorro", "O pássaro", "A tartaruga"};
    char *verbo[] = {"corre", "pula", "voa", "nada"};
    char *objeto[] = {"no jardim", "pela rua", "no céu", "no rio"};

    // Obtém o tamanho de cada array
    int numSujeitos = sizeof(sujeito) / sizeof(sujeito[0]);
    int numVerbos = sizeof(verbo) / sizeof(verbo[0]);
    int numObjetos = sizeof(objeto) / sizeof(objeto[0]);

    // Gera semente para números aleatórios
    srand((unsigned int)time(NULL));

    // Combinação aleatória das partes da frase
    printf("%s %s %s.\n", sujeito[randomInt(0, numSujeitos - 1)],verbo[randomInt(0, numVerbos - 1)],objeto[randomInt(0, numObjetos - 1)]);
}

int main() 
{
    system("clear");
    gerarFrase();

    return 0;
}
