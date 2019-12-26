#include <locale.h> /* setlocale() */
#include <stdio.h>  /* printf() */
#include <stdlib.h> /*system()*/ 
#include <string.h> /*strcpy()*/ 

typedef struct Aluno Aluno;  
struct Aluno
{
	char nome[80];
	float nota;
};


int main( int argc, char const *argv[])
{
	system("cls");

	struct Aluno A;
	//struct Aluno B;
	
	/* Artifício utilizado para silenciar o warning relativo ao não uso dos parâmetros da main() neste programa */
	argc = argc;
	argv = argv; 

	setlocale(LC_CTYPE, "");
	
	strcpy(A.nome, "Maria");
	A.nota = 10;
	
	strcpy(A.nome, "Pedro");
	A.nota = 5.0;
	
	return 0;
}
