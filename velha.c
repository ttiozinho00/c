/*Forma de compila no cmd*/
/*-std=c99 -std=gnu99 -std=c11
* use esse comando para compilar corretamente
*/

/*-Wall  -pedantic -Wextra -sdt=c99
* esse comando para correção geral do codigo
*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>

char grade[10];

int verificaPosi(int nRec)
{
    while(nRec<0 || nRec>8)
    {
        printf("\n\n\tPosição invalida: ");
        scanf("%d",&nRec);
        nRec--;

    	while(grade[nRec] == 88 || grade[nRec] == 79)
    	{     
        	printf("\n\n\tPosição já marcada:\n");
            scanf("%d",&nRec);
            nRec--;               
        }
    }
    return nRec;
}

void tela()
{
	printf("\n\t\t\t   %c | %c | %c ",grade[0],grade[1],grade[2]);
    printf("\n\t\t\t --------------");
    printf("\n\t\t\t   %c | %c | %c ",grade[3],grade[4],grade[5]);
    printf("\n\t\t\t --------------");
    printf("\n\t\t\t   %c | %c | %c ",grade[6],grade[7],grade[8]);
}

void jogador1()
{
    int num;

    printf("\n\n\n Jogador 1 -- X -- : ");
	scanf("%d",&num);

	num--;
	grade[verificaPosi(num)]=88;
}

void jogador2()
{
    int num;
    printf("\n\n\n Jogador 2 -- O -- : ");
	scanf("%d",&num);

	num--;
	grade[verificaPosi(num)]=79;
}


char venc()
{
    char g1;
    char g2;
    char g3;
   	int i;

    g1 = 0;
    g2 = 1;
    g3 = 2;

    for(i=0;i<3;i++)
	{
		if(grade[g1]== grade[g2]&& grade[g1]==grade[g3])
		{
			return grade[g1];
		}
             
        else
        { 
        	g1=g1+3; 
        	g2=g2+3; 
        	g3=g3+3;
        }

        g1=0;
        g2=3;
        g3=6;  

        for(i=0;i<3;i++)
        {
        	if(grade[g1] == grade[g2] && grade[g1] == grade[g3])
        	{
        		return grade[g1];
        	}

            else
            {
            	g1++; 
            	g2++; 
            	g3++;
            }
        }
                                   
        if(grade[0] == grade[4] && grade[0] == grade[8])
        {
        	return grade[0];
        }
                      
        if(grade[2] == grade[4] && grade[2] == grade[6])
        {
        	return grade[2]; 
        }     
	}	
}

void mensagem(char numJ)
{
    if(venc()!=0)
    {
		printf("\n\n\n\t\t--- Jogador \"%d\"  ganhou --- \"%c\" ",numJ,venc());
		getch();
		exit(0);
	}	
}

void velha(char nRec)
{
    if(nRec<=0 && venc()==0)
    {
 		printf("\n\n\n\tDeu Velha!!");
 		getch();
 		exit(0);
	}
}

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	char cont;
	int i;

	cont = 9;

    for(int i=0;i<9;++i)
    {
    	grade[i]=i+49;
    }

	while(cont)
	{
    	system("cls");
    	tela();
   		mensagem(2);
  		velha(cont);
   		jogador1();
  		cont--;

   		system("cls");
    	tela();
    	mensagem(1);
    	velha(cont);  
     	jogador2();
     	cont--;    
    }  

    getch();
	return 0;
}