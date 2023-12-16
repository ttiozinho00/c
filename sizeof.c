#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	system("cls  || clear");

	argc=argc;
	argv=argv;

	long double ld;
	int array[20];
	int *ptr;
	double d;
	float f;
	short s;
	long l;
	char c;
	int i;

	printf("sizeof c = %d\tsizeof(char) = %d\n",sizeof c,sizeof(char));
	printf("sizeof s = %d\tsizeof(short) = %d\n",sizeof s,sizeof(short));	
	printf("sizeof i = %d\tsizeof(int) = %d\n",sizeof i,sizeof(int));
	printf("sizeof l = %d\tsizeof(long) = %d\n",sizeof l,sizeof(long));
	printf("sizeof f = %d\tsizeof(float) = %d\n",sizeof f,sizeof(float));
	printf("sizeof d = %d\tsizeof(double) = %d\n",sizeof d,sizeof(double));
	printf("sizeof ld = %d\tsizeof(long double) = %d\n",sizeof ld,sizeof(long double));
	printf("sizeof array = %d\n",sizeof array);
	printf("sizeof ptr = %d\n",sizeof ptr);

	return 0;
}