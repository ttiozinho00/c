/*

Execução: gcc -o exerc18.exe exerc18.c -pedantic -Wextra -Wall

*/


#include <stdio.h>
 
int main (int argc, char *argv[])
{
   int a, b;
   
   argc =argc;
   argv = argv;
   
   printf("Digite dois numeros inteiros (a e b) para a troca\n");
   scanf("%d%d", &a, &b);
   
   a = a + b; 
   b = a - b;
   a = a - b;
 
   printf("a = %d\nb = %d\n",a,b);
   return 0;
}