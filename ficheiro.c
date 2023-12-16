#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_BUF 120

int main(int argc, char const *argv[])
{
	  // system("cls"); // Use this line if you are on Windows, otherwise, consider removing it

    FILE *f;
    int n1 = 0;
    int n2 = 0;
    char filename[80];
    char buf[MAX_BUF];

    printf("Enter the file name: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove the trailing newline character

    f = fopen(filename, "r");

    if (f == NULL) 
    {
        printf("Error opening the file\n");
        return 1;
    }

    while (fgets(buf, MAX_BUF, f) != NULL) 
    {
        n1++;

        if (strstr(buf, "printf") != NULL) 
        {
            n2++;
            printf("> %s", buf);
        } 

        else 
        {
            printf("* %s", buf);
        }
    }

    fclose(f);
    printf("\n\nThe file has %d lines, of which %d contain \"printf\"\n", n1, n2);
	return 0;
}