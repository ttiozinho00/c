#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	char string1[20];
	char string2[] = "String Literal";
	int i;

	i = 0;

	printf("Digite uma String:");
	scanf("%s",&string1[i]);

	printf("string1 é:%s\n string2 is:%s\n string1 com espaços entre caracteres é:\n",string1,string2);

	for (i = 0; string1[ i ] != '\0'; i++)
	{
		printf("%c\n",string1[i]);
	}
	printf("\n");

	return 0;
}