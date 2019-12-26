#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	int nota;
	int acont;
	int bcont;
	int ccont;
	int dcont;
	int fcont;

	printf("Informe as notas em letra");
	printf("Digite o caractere EOF para encerrar a entrada");

	while((nota = getchar())!=EOF)
	{
		switch(nota)
		{
			case 'A':
			case 'a':
				++acont;	
				break;

			case 'B':
			case 'b':
				++bcont;	
				break;

			case 'C':
			case 'c':
				++ccont;	
				break;

			case 'D':
			case 'd':
				++dcont;	
				break;	

			case 'F':
			case 'f':
				++fcont;	
				break;

			case '\n':
			case '\t':
			/*case "":*/
			break;

			default:
				printf("Letra de nota incorreta\n");
				printf("Digite nova nota.\n");
				break;					
		}

		printf("\nTotais para cada nota são:");
		printf("A: %d\n",acont);
		printf("B: %d\n",bcont);
		printf("C: %d\n",ccont);
		printf("D: %d\n",dcont);
		printf("F: %d\n",fcont);	
	}

	return 0;
}