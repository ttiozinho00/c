/*
* compilar: gcc -o calculadora_linux calculadora_linux.c $(pkg-config --cflags --libs gtk+-3.0) -Wall -pedantic -Wextra -Werror -lm
*/

#include <gtk/gtk.h>
#include <math.h>

// Estrutura para armazenar dados adicionais
typedef struct 
{
    GtkWidget *textbox;
    double currentValue;
    double storedValue;
    char currentOperation;
    gboolean isDecimalPressed;
} CalculatorData;

void updateTextBox(CalculatorData *data) 
{
    gchar *text = g_strdup_printf("%.15g", data->currentValue);
    gtk_entry_set_text(GTK_ENTRY(data->textbox), text);
    g_free(text);
}

static void button_clicked(GtkWidget *button, gpointer user_data) 
{
    CalculatorData *data = (CalculatorData *)user_data;
    const char *label = gtk_button_get_label(GTK_BUTTON(button));

    if (g_strcmp0(label, "C") == 0) 
    {
        data->currentValue = 0;
        data->storedValue = 0;
        data->currentOperation = ' ';
        data->isDecimalPressed = FALSE;
    } 

    else if (g_strcmp0(label, "=") == 0) 
    {
        switch (data->currentOperation) 
        {
            case '+':
                data->currentValue = data->storedValue + data->currentValue;
                break;
            case '-':
                data->currentValue = data->storedValue - data->currentValue;
                break;
            case '*':
                data->currentValue = data->storedValue * data->currentValue;
                break;
            case '/':
                if (data->currentValue != 0) 
                {
                    data->currentValue = data->storedValue / data->currentValue;
                } 

                else 
                {
                    // Handle division by zero
                    g_print("Error: Division by zero\n");
                    data->currentValue = 0;
                }
                break;
        }
        data->storedValue = 0;
        data->currentOperation = ' ';
        data->isDecimalPressed = FALSE;

        // Atualizar a caixa de texto após a operação
        updateTextBox(data);
    } 

    else if (g_strcmp0(label, ".") == 0) 
    {
        if (!data->isDecimalPressed) 
        {
            data->isDecimalPressed = TRUE;
            data->currentValue += 0.0;
        }
    } 

    else if (g_ascii_isdigit(label[0])) 
    {
        int digit = atoi(label);
        data->currentValue = data->currentValue * 10 + digit;

        if (data->isDecimalPressed) 
        {
            data->isDecimalPressed = FALSE;
            double decimalPart = digit;

            while (decimalPart >= 1.0) 
            {
                decimalPart /= 10.0;
            }

            data->currentValue += decimalPart;
        }
    }

    else if (g_strcmp0(label, "Sin") == 0) 
    {
        data->currentValue = sin(data->currentValue);
    }

    else if (g_strcmp0(label, "Cos") == 0) 
    {
        data->currentValue = cos(data->currentValue);
    }

    else if (g_strcmp0(label, "Tan") == 0) 
    {
        data->currentValue = tan(data->currentValue);
    }

    else if (g_strcmp0(label, "Sqrt") == 0) 
    {
        data->currentValue = sqrt(data->currentValue);
    }

    else if (g_strcmp0(label, "Exp") == 0) 
    {
        data->currentValue = exp(data->currentValue);
    }

    else if (g_strcmp0(label, "Log") == 0) 
    {
        data->currentValue = log(data->currentValue);
    } 

    else 
    {
        data->storedValue = data->currentValue;
        data->currentValue = 0;
        data->currentOperation = label[0];
        data->isDecimalPressed = FALSE;
    }

    // Atualizar a caixa de texto após a operação
    updateTextBox(data);
}

int main(int argc, char *argv[]) 
{
    gtk_init(&argc, &argv);

    GtkWidget *window, *grid, *button;
    CalculatorData data;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_window_set_title(GTK_WINDOW(window), "Scientific Calculator");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    data.textbox = gtk_entry_new();
    gtk_entry_set_alignment(GTK_ENTRY(data.textbox), 1.0);
    gtk_entry_set_width_chars(GTK_ENTRY(data.textbox), 20);
    gtk_grid_attach(GTK_GRID(grid), data.textbox, 0, 0, 4, 1);

    const char *buttonLabels[] = {"Sin", "Cos", "Tan", "Sqrt", "Exp", "Log", "C", "=", "+", "-", "*", "/", ".", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    for (int i = 0; i < (int)G_N_ELEMENTS(buttonLabels); i++) 
    {
        button = gtk_button_new_with_label(buttonLabels[i]);
        g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), &data);
        gtk_grid_attach(GTK_GRID(grid), button, i % 5, i / 5 + 1, 1, 1);
    }

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}