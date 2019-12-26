#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	int frequencia1;
	int frequencia2;
	int frequencia3;
	int frequencia4;
	int frequencia5;
	int frequencia6;
	int cont;
	int face;

	frequencia1 = 0;
	frequencia2 = 0;
	frequencia3 = 0;
	frequencia4 = 0;
	frequencia5 = 0;
	frequencia6 = 0;

	for (cont = 0; cont <= 6000+1;cont++)
	{
		face = 1 + rand()%6;

		switch(face)
		{
			case 1:
				++frequencia1;
				break;

			case 2:
				++frequencia2;
				break;	

			case 3:
				++frequencia3;
				break;	

			case 4:
				++frequencia4;
				break;
				
			case 5:
				++frequencia5;
				break;	

			case 6:
				++frequencia6;
				break;		
		} 
	}

	printf("%s%13s\n","Face","Frequência");
	printf(" 1%13d\n",frequencia1);
	printf(" 2%13d\n",frequencia2);
	printf(" 3%13d\n",frequencia3);
	printf(" 4%13d\n",frequencia4);
	printf(" 5%13d\n",frequencia5);
	printf(" 6%13d\n",frequencia6);

	return 0;
}