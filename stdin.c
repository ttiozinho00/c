#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) 
{
    system("cls");

    argc=argc;
    argv=argv;

    if (argc == 2)
	{  
		fputs(argv[1], stdout);
	}

    char buf[128];
    
    while (fgets(buf, 128, stdin)) 
	{
        fputs(buf, stdout);
    }

    return 77;
}