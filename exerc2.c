/*

Execução: gcc -o exerc2.exe exerc2.c -pedantic -Wextra -Wall -Werror

*/

#include <stdio.h>   /*printf(), scanf() */
#include <string.h>  /*strlen() */
#include <conio.h>   /*getchar() */
#include <windows.h> /* SetConsoleCursorPosition, GetStdHandle() , STD_OUTPUT_HANDLE*/

//Função gotoxy responsavel por setar as coordenadas no eixo x e y;
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main (int argc, char *argv[])
{
    char categoria[100], nome[100];
    
    int numCaracterS1=0,numCaracterS2=0, meio=0;
  	argc = argc;
  	argv = argv;

    printf("Digite S1, ex: Nomes: ");
    scanf("%[^\n]s",&categoria);
    getchar();

    printf("Digite S2, ex: Cezar Garrido: ");
    scanf("%[^\n]s", &nome); // todos os caracteres com exceção do \n
    getchar();
    numCaracterS1 = strlen(categoria);
    numCaracterS2 = strlen(nome);

    meio = numCaracterS2 / 2;
    meio = meio - numCaracterS1/2;

    system("cls"); 
    gotoxy(meio, 0);
 
    printf("%s",categoria);
    gotoxy(0, 1);

    printf("%s",nome);

    return 0;

}
