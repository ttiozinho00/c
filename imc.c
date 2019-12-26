#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    system("cls");

    argc=argc;
    argv=argv;

    int idade;
    float imc;
    float p;
    float a;

    printf("Digite sua idade:");
    scanf("%d",&idade);

    printf("Digite o seu peso:");
    scanf("%f",&p);

    printf("Digite a sua altura:");
    scanf("%f",&a);


    imc = p / (a*a);

    if (imc < 26)
    {
        printf("O seu Indice de Massa Corporea e %.2f e esta Normal\n", imc);
    }
            
    if (imc >=26 &&  imc<30)
    {
        printf ("O seu Indice de Massa Corporea e %.2f e voce esta Obeso\n", imc);
    }
        
    if (imc >=30)
    {
        printf("O seu Indice de Massa Corporea e %.2f e voce esta com Obesidade Morbida\n", imc);
    }

    if (idade>=18)
    {
        printf("Você é maior de idade");
    }

    if (idade <18)
    {
        printf("Você é menor de idade");
    }

    return 0;
}