#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <conio.h>
#define CLEAR_SCREEN "cls"
#elif __linux__
#include <stdio_ext.h>
#include <termios.h>
#define CLEAR_SCREEN "clear"
#endif

#include <locale.h>

char grade[10];

int verificaPosi(int nRec) 
{
    while (nRec < 0 || nRec > 8) 
    {
        printf("\n\n\tPosição inválida: ");
        scanf("%d", &nRec);
        nRec--;

        while (grade[nRec] == 'X' || grade[nRec] == 'O') 
        {
            printf("\n\n\tPosição já marcada:\n");
            scanf("%d", &nRec);
            nRec--;
        }
    }
    return nRec;
}

void tela()
{
    printf("\n\t\t\t   %c | %c | %c ", grade[0], grade[1], grade[2]);
    printf("\n\t\t\t --------------");
    printf("\n\t\t\t   %c | %c | %c ", grade[3], grade[4], grade[5]);
    printf("\n\t\t\t --------------");
    printf("\n\t\t\t   %c | %c | %c ", grade[6], grade[7], grade[8]);
}

void jogador1() 
{
    int num;

    printf("\n\n\n Jogador 1 -- X -- : ");
    scanf("%d", &num);

    num--;
    grade[verificaPosi(num)] = 'X';
}

void jogador2() 
{
    int num;
    printf("\n\n\n Jogador 2 -- O -- : ");
    scanf("%d", &num);

    num--;
    grade[verificaPosi(num)] = 'O';
}

char venc()
{
    int i;

    for (i = 0; i < 3; i++) 
    {
        if (grade[i] == grade[i + 3] && grade[i] == grade[i + 6]) 
        {
            return grade[i];
        }
    }

    for (i = 0; i < 9; i += 3) 
    {
        if (grade[i] == grade[i + 1] && grade[i] == grade[i + 2]) 
        {
            return grade[i];
        }
    }

    if (grade[0] == grade[4] && grade[0] == grade[8]) 
    {
        return grade[0];
    }

    if (grade[2] == grade[4] && grade[2] == grade[6]) 
    {
        return grade[2];
    }

    return 0;
}

void mensagem(char numJ) 
{
    (void)numJ;
    if (venc() != 0) 
    {
        printf("\n\n\n\t\t--- Jogador \"%c\"  ganhou ---", venc());
        getchar(); // Use getchar() instead of getch()
        _Exit(0);
    }
}

void velha(int nRec) 
{
    if (nRec <= 0 && venc() == 0) 
    {
        printf("\n\n\n\tDeu Velha!!");
        getchar();
        _Exit(0);
    }
}

int main(int argc, char const *argv[])
{
    (void)argv[argc];
    
    system(CLEAR_SCREEN);
    setlocale(LC_ALL, "");

    char cont;
    int i;

    cont = 9;

    for (i = 0; i < 9; ++i) 
    {
        grade[i] = i + '1';
    }

    while (cont) 
    {
        system(CLEAR_SCREEN);
        tela();
        mensagem('2');
        velha(cont);
        jogador1();
        cont--;

        system(CLEAR_SCREEN);
        tela();
        mensagem('1');
        velha(cont);
        jogador2();
        cont--;
    }

    getchar(); // Use getchar() instead of getch()
    return 0;
}
