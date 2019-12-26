#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argc=argc;
	argv=argv;

	float fpi = 3.1415;
	float **ppf;
	float *pf;

	pf = &fpi;
	ppf = &pf; 

	printf("\n");
	printf("%f", **ppf);     
    printf("%f", *pf);
    printf("\n");

	return 0;
}