
#include <conio.h>   /* getche 	 */
#include <stdio.h>   /* printf() */
#include <stdlib.h> /*system()*/
 	 

/* Início do programa */
int main(int argc, char *argv[])
{
	/*Limpar a Tela*/
	system("cls");
	
	/* Variável que contera  um dígito convertido para inteiro */
	int digito_cpf; 
	
	/* Variável contadora do laço */
	int i; 
	
	int multiplicacao_extra_calculo_digito_2; 
	
	/* Somatória de todos os valores já  multiplicados */
	int soma_digito_1;
	int soma_digito_2;
	
	/* Dígitos verificadores calculados */
	int digito_1;
	int digito_2;
	
	/* Silenciar warning relativo ao não uso do parâmetro argc */
	argc = argc;
	argv = argv;

	/* Laço que lerá todos os dígitos do CPF */
	soma_digito_1 = 0;
	soma_digito_2 = 0;
	
	for (i = 0; i <= 8; i++) 
	{
		digito_cpf = getche() - '0'; /* Convertendo o caracter i para o digito i */
		soma_digito_1 = soma_digito_1 + digito_cpf * (i + 1);
		soma_digito_2 = soma_digito_2 + digito_cpf * i;
	}
	
	/* Armazenando o digito 1 calculado já com o ajuste indicado pela observação (o resto ser maior que 9 então o dígito vale 0) */
	digito_1 = 	((soma_digito_1 % 11) > 9)  ? (0) : soma_digito_1 % 11;
	
	/* O digito 2 exige mais uma multiplicação que envolve o próprio dígito 1 */
	multiplicacao_extra_calculo_digito_2 = soma_digito_2 + 9 * digito_1;
	
	/* Armazenando o digito 2 calculado já com o ajuste indicado pela observação (o resto ser maior que 9 então o dígito vale 0) */
	digito_2 = ( (multiplicacao_extra_calculo_digito_2 % 11) > 9 ) ? (0) : (multiplicacao_extra_calculo_digito_2 % 11);
	
	/* Imprimir os dois dígitos verificadores */
	printf("-");
	printf("%d", digito_1);
	printf("%d", digito_2);

	/* Indicar que o programa foi encerrado com sucesso */
	return 0;
}