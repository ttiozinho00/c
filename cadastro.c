#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h> 

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

// Estrutura para representar um usuário
typedef struct 
{
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

// Função para registrar um novo usuário
void registerUser(User users[], int *numUsers) 
{
    if (*numUsers >= MAX_USERS) 
    {
        printf("Limite máximo de usuários atingido.\n");
        return;
    }

    printf("Digite o nome de usuário: ");
    scanf("%s", users[*numUsers].username);

    printf("Digite a senha: ");

    // Desabilitar a exibição de caracteres no terminal
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Ler a senha sem exibir no terminal
    scanf("%s", users[*numUsers].password);

    // Restaurar configurações originais do terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    (*numUsers)++;
    printf("\nUsuário registrado com sucesso!\n");
}

// Função para fazer login
void login(User users[], int numUsers) 
{
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Digite o nome de usuário: ");
    scanf("%s", username);

    printf("Digite a senha: ");

    /* Desabilitar a exibição de caracteres no terminal */
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    /* Ler a senha sem exibir no terminal */
    scanf("%s", password);

    /* Restaurar configurações originais do terminal */
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    for (int i = 0; i < numUsers; i++) 
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) 
        {
            printf("\nLogin bem-sucedido!\n");
            return;
        }
    }

    printf("\nNome de usuário ou senha incorretos.\n");
}

int main(int argc, char const *argv[])
{
    (void)argv[argc];

    system("clear");

    User users[MAX_USERS];
    int numUsers = 0;
    int choice;

    do 
    {
        printf("\n1. Registrar\n");
        printf("2. Login\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                system("clear");
                registerUser(users, &numUsers);
                break;
            case 2:
                system("clear");
                login(users, numUsers);
                break;
            case 3:
                system("clear");
                printf("Saindo...\n");
                exit(0);
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
