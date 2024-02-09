#include <gtk/gtk.h>
#include <string.h>

typedef struct 
{
    char username[50];
    char password[50];
    double saldo;
} Conta;

// Função para realizar o login
int login(Conta *contas, int totalContas, const char *username, const char *password) 
{
    for (int i = 0; i < totalContas; i++) 
    {
        if (strcmp(contas[i].username, username) == 0 && strcmp(contas[i].password, password) == 0) 
        {
            return i; // Retorna o índice da conta
        }
    }
    return -1; // Retorna -1 se o login falhar
}

// Função para criar uma nova conta
void criarConta(Conta *contas, int *totalContas) 
{
    GtkWidget *dialog;
    GtkWidget *content_area;
    GtkWidget *label;
    GtkWidget *entry;
    gchar *text;
    gint result;
    double saldo;

    // Criação de uma janela de diálogo
    dialog = gtk_dialog_new_with_buttons("Criar Nova Conta",NULL,GTK_DIALOG_MODAL,"OK", GTK_RESPONSE_OK,"Cancelar", GTK_RESPONSE_CANCEL,NULL);

    // Obtenção da área de conteúdo do diálogo
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    // Adição de um rótulo ao diálogo
    label = gtk_label_new("Digite seu nome de usuário:");
    gtk_container_add(GTK_CONTAINER(content_area), label);

    // Adição de uma entrada de texto ao diálogo
    entry = gtk_entry_new();
    gtk_container_add(GTK_CONTAINER(content_area), entry);
    gtk_widget_show(entry);

    // Execução do diálogo
    result = gtk_dialog_run(GTK_DIALOG(dialog));

    if (result == GTK_RESPONSE_OK) 
    {
        // Obtenção do texto da entrada
        text = g_strdup(gtk_entry_get_text(GTK_ENTRY(entry)));
        strcpy(contas[*totalContas].username, text);

        // Implementação básica de criptografia para a senha (substituir por um método mais seguro em produção)
        label = gtk_label_new("Digite sua senha:");
        gtk_container_add(GTK_CONTAINER(content_area), label);
        entry = gtk_entry_new();
        gtk_entry_set_visibility(GTK_ENTRY(entry), FALSE); // Oculta a senha
        gtk_container_add(GTK_CONTAINER(content_area), entry);
        gtk_widget_show(entry);

        result = gtk_dialog_run(GTK_DIALOG(dialog));

        if (result == GTK_RESPONSE_OK) 
        {
            // Obtenção do texto da entrada
            text = g_strdup(gtk_entry_get_text(GTK_ENTRY(entry)));
            strcpy(contas[*totalContas].password, text);

            // Adição de um rótulo para o saldo
            label = gtk_label_new("Digite o saldo inicial:");
            gtk_container_add(GTK_CONTAINER(content_area), label);

            // Adição de uma entrada de ttk_entry_new();
            gtk_container_add(GTK_CONTAINER(content_area), entry);
            gtk_widget_show(entry);

            // Execução do diálogo
            result = gtk_dialog_run(GTK_DIALOG(dialog));

            if (result == GTK_RESPONSE_OK) 
            {
                // Obtenção do texto da entrada e conversão para double
                text = g_strdup(gtk_entry_get_text(GTK_ENTRY(entry)));
                saldo = atof(text);
                contas[*totalContas].saldo = saldo;

                // Incremento do total de contas
                (*totalContas)++;
                
                // Exibição de uma mensagem de sucesso
                GtkWidget *success_dialog = gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Conta criada com sucesso!");
                gtk_dialog_run(GTK_DIALOG(success_dialog));
                gtk_widget_destroy(success_dialog);
            }
        }
    }

    // Destruir o diálogo após o uso
    gtk_widget_destroy(dialog);
}

// Função para consultar saldo
void consultarSaldo(Conta *contas, int indiceConta) 
{
    GtkWidget *dialog;
    GtkWidget *label;
    gchar *text;

    // Criação de uma janela de diálogo
    dialog = gtk_dialog_new_with_buttons("Consulta de Saldo",NULL,GTK_DIALOG_MODAL,"OK", GTK_RESPONSE_OK,NULL);

    // Obtenção da área de conteúdo do diálogo
    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    // Adição de um rótulo ao diálogo
    label = gtk_label_new("Saldo disponível:");
    gtk_container_add(GTK_CONTAINER(content_area), label);

    // Conversão do saldo para string
    text = g_strdup_printf("%.2f", contas[indiceConta].saldo);

    // Adição de um rótulo para exibir o saldo
    label = gtk_label_new(text);
    gtk_container_add(GTK_CONTAINER(content_area), label);

    // Exibição do diálogo
    gtk_widget_show_all(dialog);

    // Execução do diálogo
    gtk_dialog_run(GTK_DIALOG(dialog));

    // Destruir o diálogo após o uso
    gtk_widget_destroy(dialog);

    // Liberação da memória alocada para o texto
    g_free(text);
}

// Função para realizar saque
void sacar(Conta *contas, int indiceConta, double valor) 
{
    if (valor > 0 && contas[indiceConta].saldo >= valor) 
    {
        contas[indiceConta].saldo -= valor;

        // Criação de uma janela de diálogo para exibir a mensagem de saque
        GtkWidget *success_dialog = gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Saque de %.2f realizado com sucesso. Novo saldo: %.2f", valor, contas[indiceConta].saldo);

        // Exibição do diálogo
        gtk_dialog_run(GTK_DIALOG(success_dialog));

        // Destruir o diálogo após o uso
        gtk_widget_destroy(success_dialog);
    } 
    else 
    {
        // Criação de uma janela de diálogo para exibir a mensagem de erro
        GtkWidget *error_dialog = gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Erro: Saldo insuficiente ou valor inválido.");

        // Exibição do diálogo
        gtk_dialog_run(GTK_DIALOG(error_dialog));

        // Destruir o diálogo após o uso
        gtk_widget_destroy(error_dialog);
    }
}

// Função para realizar depósito
void depositar(Conta *contas, int indiceConta, double valor) 
{
    if (valor > 0) 
    {
        contas[indiceConta].saldo += valor;

        // Criação de uma janela de diálogo para exibir a mensagem de depósito
        GtkWidget *success_dialog = gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Depósito de %.2f realizado com sucesso. Novo saldo: %.2f", valor, contas[indiceConta].saldo);

        // Exibição do diálogo
        gtk_dialog_run(GTK_DIALOG(success_dialog));

        // Destruir o diálogo após o uso
        gtk_widget_destroy(success_dialog);
    } 
    else 
    {
        // Criação de uma janela de diálogo para exibir a mensagem de erro
        GtkWidget *error_dialog = gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Erro: Valor inválido para depósito.");

        // Exibição do diálogo
        gtk_dialog_run(GTK_DIALOG(error_dialog));

        // Destruir o diálogo após o uso
        gtk_widget_destroy(error_dialog);
    }
}

// Função para salvar contas em um arquivo
void salvarContas(Conta *contas, int totalContas) 
{
    FILE *arquivo = fopen("contas.txt", "w");
    if (arquivo == NULL) 
    {
        printf("Erro ao salvar contas.\n");
        return;
    }

    for (int i = 0; i < totalContas; i++) 
    {
        fprintf(arquivo, "%s %s %.2f\n", contas[i].username, contas[i].password, contas[i].saldo);
    }

    fclose(arquivo);
}

// Função para carregar contas de um arquivo
int carregarContas(Conta *contas) 
{
    FILE *arquivo = fopen("contas.txt", "r");
    if (arquivo == NULL) 
    {
        printf("Erro ao carregar contas.\n");
        return 0;
    }

    int totalContas = 0;
    while (fscanf(arquivo, "%s %s %lf", contas[totalContas].username, contas[totalContas].password, &contas[totalContas].saldo) == 3) 
    {
        totalContas++;
    }

    fclose(arquivo);
    return totalContas;
}

int main(int argc, char *argv[]) 
{
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *buttonCriarConta, *buttonConsultarSaldo, *buttonSacar, *buttonDepositar, *buttonSair;
    Conta contas[10]; // Aumentei o tamanho para 10 contas
    int totalContas = carregarContas(contas);

    // Inicialização do GTK
    gtk_init(&argc, &argv);

    // Criação da janela principal
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "ATM - GTK");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Criação de um layout em grade para organizar os widgets
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Botão para criar conta
    buttonCriarConta = gtk_button_new_with_label("Criar Conta / Login");
    g_signal_connect(buttonCriarConta, "clicked", G_CALLBACK(criarConta), &contas);
    gtk_grid_attach(GTK_GRID(grid), buttonCriarConta, 0, 0, 1, 1);

    // Botão para consultar saldo
    buttonConsultarSaldo = gtk_button_new_with_label("Consultar Saldo");
    g_signal_connect(buttonConsultarSaldo, "clicked", G_CALLBACK(consultarSaldo), &contas);
    gtk_grid_attach(GTK_GRID(grid), buttonConsultarSaldo, 1, 0, 1, 1);

    // Botão para sacar
    buttonSacar = gtk_button_new_with_label("Sacar");
    g_signal_connect(buttonSacar, "clicked", G_CALLBACK(sacar), &contas);
    gtk_grid_attach(GTK_GRID(grid), buttonSacar, 2, 0, 1, 1);

    // Botão para depositar
    buttonDepositar = gtk_button_new_with_label("Depositar");
    g_signal_connect(buttonDepositar, "clicked", G_CALLBACK(depositar), &contas);
    gtk_grid_attach(GTK_GRID(grid), buttonDepositar, 3, 0, 1, 1);

    // Botão para sair
    buttonSair = gtk_button_new_with_label("Sair");
    g_signal_connect(buttonSair, "clicked", G_CALLBACK(gtk_main_quit), NULL);
    gtk_grid_attach(GTK_GRID(grid), buttonSair, 4, 0, 1, 1);

    // Exibição de todos os widgets
    gtk_widget_show_all(window);

    // Execução do loop principal do GTK
    gtk_main();

    // Salvar contas antes de sair
    salvarContas(contas, totalContas);

    return 0;
}
