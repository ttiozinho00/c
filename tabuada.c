#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // Use system("clear") for Unix/Linux or system("clear || cls") for a cross-platform solution
    system("cls");

    // Unused arguments, so assigning them to themselves to avoid warnings
    argv = argv;
    argc = argc;

    int j; // Change the loop variable to 'j'

    printf("Informe o valor:\n");
    scanf("%d", &j); // Change the variable to 'j'

    for (j = 0; j < 10; j++) // Fix the loop condition and variable
    {
        printf("%d\n", j);
    }

    return 0;
}
