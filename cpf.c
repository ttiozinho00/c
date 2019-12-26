
#include <conio.h>   /* getche 	 */
#include <stdio.h>   /* printf() */
#include <stdlib.h> /*system()*/
 	 

/* In�cio do programa */
int main(int argc, char *argv[])
{
	/*Limpar a Tela*/
	system("cls");
	
	/* Vari�vel que contera  um d�gito convertido para inteiro */
	int digito_cpf; 
	
	/* Vari�vel contadora do la�o */
	int i; 
	
	int multiplicacao_extra_calculo_digito_2; 
	
	/* Somat�ria de todos os valores j�  multiplicados */
	int soma_digito_1;
	int soma_digito_2;
	
	/* D�gitos verificadores calculados */
	int digito_1;
	int digito_2;
	
	/* Silenciar warning relativo ao n�o uso do par�metro argc */
	argc = argc;
	argv = argv;

	/* La�o que ler� todos os d�gitos do CPF */
	soma_digito_1 = 0;
	soma_digito_2 = 0;
	
	for (i = 0; i <= 8; i++) 
	{
		digito_cpf = getche() - '0'; /* Convertendo o caracter i para o digito i */
		soma_digito_1 = soma_digito_1 + digito_cpf * (i + 1);
		soma_digito_2 = soma_digito_2 + digito_cpf * i;
	}
	
	/* Armazenando o digito 1 calculado j� com o ajuste indicado pela observa��o (o resto ser maior que 9 ent�o o d�gito vale 0) */
	digito_1 = 	((soma_digito_1 % 11) > 9)  ? (0) : soma_digito_1 % 11;
	
	/* O digito 2 exige mais uma multiplica��o que envolve o pr�prio d�gito 1 */
	multiplicacao_extra_calculo_digito_2 = soma_digito_2 + 9 * digito_1;
	
	/* Armazenando o digito 2 calculado j� com o ajuste indicado pela observa��o (o resto ser maior que 9 ent�o o d�gito vale 0) */
	digito_2 = ( (multiplicacao_extra_calculo_digito_2 % 11) > 9 ) ? (0) : (multiplicacao_extra_calculo_digito_2 % 11);
	
	/* Imprimir os dois d�gitos verificadores */
	printf("-");
	printf("%d", digito_1);
	printf("%d", digito_2);

	/* Indicar que o programa foi encerrado com sucesso */
	return 0;
}