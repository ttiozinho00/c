#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void uselocal(void);
void usestaticlocal(void);
void useglobal(void);

int x = 1;

void uselocal(void)
{
	int x = 25;

	printf("\n local em useLocal é:%d após entrar em useLocal\n",x);
	x++;
	printf("\n local em useLocal é:%d antes entrar em useLocal\n",x);
}

void usestaticlocal(void)
{
	static int x = 50;

	printf("\n x estática local é:%d na entrada de useStaticLocal\n",x);
	x++;
	printf("\n x estática local é:%d na saída de useStaticLocal\n",x);
}

void useglobal(void)
{
	printf("\n x global é:%d na entrada de useGlobal\n",x);
	x *= 10;
	printf("\n x global é:%d na saída de useGlobal\n",x);

}

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	int x = 5;

	printf("x local no escopo externo da main é:%d\n",x);

	{
		int x = 7;
		printf("x local no escopo interno de main é:%d\n",x);
	}

	printf("x local no escopo externo da main é:%d\n",x);

	uselocal();
	usestaticlocal();
	useglobal();

	uselocal();
	usestaticlocal();
	useglobal();

	printf("\n x local em main é:%d\n",x);

	return 0;
}