#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define zero 0
#define op2 2

typedef struct arvore
{
    int numero;
    int freq;
    struct arvore *dir;
    struct arvore *esq;
} No;

No *inserir(No **Raiz, int numero);
void listarpornivel(No **Raiz, int nivel);
No *consulta_nodo(No *Raiz, int numero);
void OrdemCrescente(No *Raiz);
void OrdemDecrescente(No *Raiz);
void imprimeArvore2(No *Raiz);
No *iniciaArvore(No **Raiz);
void imprimeArvore(No *Raiz);
int maior(int a, int b);
int altura(No *pRaiz);
void listarpornivel2(No **Raiz, int nivel);
void imprimeFreqc(No *Raiz, int k);
void ValidarArvoreEsq(No *Raiz);
void ValidarArvoreDir(No *Raiz);

void limpastring(char stringtext[]);

int main(void)
{
    system("cls");

    No *lista = NULL, *listaux = NULL;

    char entrada[31];
    char aux[31];
    int dado;

    while (strcmp(entrada, "e") != 0)
    {

        fflush(stdin);
        fgets(entrada, sizeof(entrada), stdin);
        limpastring(aux);

        switch (entrada[0])
        {

        case 'i':
        {

            while (strcmp(entrada, "{FONTE}") == 0)
            {
                strcpy(aux, entrada);
                fgets(entrada, sizeof(entrada), stdin);
            }

            strcpy(aux, "{FONTE}");
            dado = atoi(aux);
            listaux = consulta_nodo(lista, dado);

            if ((consulta_nodo(lista, dado)) == NULL)
            {
                inserir(&lista, dado);
            }
        }
        break;

        case 'c':
        {

            while (strcmp(entrada, "{FONTE}") != 0)
            {
                strcpy(aux, entrada);
                fgets(entrada, sizeof(entrada), stdin);
            }

            strcpy(aux, "{FONTE}");
            dado = atoi(aux);
            listaux = consulta_nodo(lista, dado);

            if ((consulta_nodo(lista, dado)) == NULL)
            {
                printf("nao existe no com chave: %d\n", dado);
            }

            else
            {
                listaux->freq++;
                printf("existe no com chave: %d\n", listaux->numero);
            }
        }
        break;

        case 'p':

            switch (entrada[op2])
            {

            case 'c':
                OrdemCrescente(lista);
                break;

            case 'd':
                OrdemDecrescente(lista);
                break;

            default:
                break;
            }

            printf("\n");
            break;

        case 'd':

            imprimeArvore(lista);
            break;

        case 'f':
        {

            while (strcmp(entrada, "{FONTE}") != 0)
            {
                strcpy(aux, entrada);
                fgets(entrada, sizeof(entrada), stdin);
            }

            strcpy(aux, "{FONTE}");
            dado = atoi(aux);
            listaux = consulta_nodo(lista, dado);

            if (listaux != NULL)
            {
                printf("%d\n", listaux->freq);
            }

            else
            {
                printf("\n");
            }
        }
        break;

        case 'n':
        {

            while (strcmp(entrada, "{FONTE}") != 0)
            {
                strcpy(aux, entrada);
                fgets(entrada, sizeof(entrada), stdin);
            }

            strcpy(aux, "{FONTE}");
            dado = atoi(aux);

            if (dado >= 1)
            {
                listarpornivel(&lista, dado);
            }

            else
            {
                printf("\n");
            }
        }
        break;

        case 'k':
        {

            while (strcmp(entrada, "{FONTE}") != 0)
            {
                strcpy(aux, entrada);
                fgets(entrada, sizeof(entrada), stdin);
            }

            strcpy(aux, "{FONTE}");
            dado = atoi(aux);

            if (dado >= 1)
            {
                imprimeFreqc(lista, dado);
            }

            else
            {
                printf("\n");
            }
        }
        break;

        default:
            break;
            printf("\n");
        }
    }
    return 0;
}

void limpastring(char stringtext[])
{
    int value = (strlen(stringtext));
    int i;

    for (i = 0; i < value; i++)
    {
        stringtext[i] = '\0';
    }
}

No *inserir(No **Raiz, int numero)
{
    if (*Raiz == NULL)
    {
        *Raiz = (No *)malloc(sizeof(No));
        (*Raiz)->esq = NULL;
        (*Raiz)->dir = NULL;
        (*Raiz)->numero = numero;
        (*Raiz)->freq = zero;
        return (*Raiz);
    }

    else
    {
        if (numero < (*Raiz)->numero)
        {
            return inserir(&(*Raiz)->esq, numero);
        }

        else
        {
            return inserir(&(*Raiz)->dir, numero);
        }
    }
}

No *consulta_nodo(No *Raiz, int numero)
{

    if (Raiz == NULL)
    {
        return NULL;
    }

    if (Raiz->numero == numero)
    {
        return Raiz;
    }

    if (numero < Raiz->numero)
    {
        return consulta_nodo(Raiz->esq, numero);
    }

    else
    {
        return consulta_nodo(Raiz->dir, numero);
    }
}

void OrdemCrescente(No *Raiz)
{
    if (Raiz != NULL)
    {
        OrdemCrescente(Raiz->esq);
        printf("\n%d %d", Raiz->numero, Raiz->freq);
        OrdemCrescente(Raiz->dir);
    }
}

void OrdemDecrescente(No *Raiz)
{
    if (Raiz != NULL)
    {
        OrdemDecrescente(Raiz->dir);
        printf("\n%d %d", Raiz->numero, Raiz->freq);
        OrdemDecrescente(Raiz->esq);
    }
}

void imprimeArvore(No *Raiz)
{
    if (Raiz != NULL)
    {
        imprimeArvore(Raiz->esq);
        printf("\nchave: %d", Raiz->numero);

        if (Raiz->esq != NULL)
        {
            printf(" filho esquerdo: %d", Raiz->esq->numero);
        }

        else
        {
            printf(" filho esquerdo: nil");
        }

        if (Raiz->dir != NULL)
        {
            printf(" filho direito: %d\n", Raiz->dir->numero);
        }

        else
        {
            printf(" filho direito: nil\n");
        }
        imprimeArvore(Raiz->dir);
    }
}

void listarpornivel(No **Raiz, int nivel)
{
    if ((nivel == 1) && (*Raiz != NULL))
    {
        printf("%d %d\n", (*Raiz)->numero, (*Raiz)->freq);
    }

    else
    {
        if ((*Raiz)->esq != NULL)
        {
            listarpornivel(&(*Raiz)->esq, nivel - 1);
        }

        if ((*Raiz)->dir != NULL)
        {
            listarpornivel(&(*Raiz)->dir, nivel - 1);
        }
    }
}

void imprimeArvore2(No *Raiz)
{
    if (Raiz != NULL)
    {
        imprimeArvore2(Raiz->esq);
        printf("\nchave: %d", Raiz->numero);
        imprimeArvore2(Raiz->dir);
    }
}

void imprimeFreqc(No *Raiz, int k)
{
    if (Raiz != NULL)
    {
        imprimeFreqc(Raiz->esq, k);

        if (Raiz->freq == k || Raiz->freq > k)
        {
            printf("\n%d", Raiz->numero);
            imprimeFreqc(Raiz->dir, k);
        }
    }
}

void ValidarArvoreEsq(No *Raiz)
{
    int tpfreq;
    int tpnum;

    tpfreq = 0;
    tpnum = 0;

    if (Raiz != NULL)
    {
        if (Raiz->esq != NULL && Raiz->freq < Raiz->esq->freq)
        {
            tpnum = Raiz->numero;
            tpfreq = Raiz->freq;
            Raiz->numero = Raiz->esq->numero;
            Raiz->freq = Raiz->esq->freq;
            Raiz->esq->numero = tpnum;
            Raiz->esq->freq = tpfreq;
        }

        else
        {
            ValidarArvoreEsq(Raiz->esq);
        }
    }
}

void ValidarArvoreDir(No *Raiz)
{
    int tpfreq;
    int tpnum;

    tpfreq = 0;
    tpnum = 0;

    if (Raiz != NULL)
    {
        if (Raiz->dir != NULL && Raiz->freq < Raiz->dir->freq)
        {
            tpnum = Raiz->numero;
            tpfreq = Raiz->freq;
            Raiz->numero = Raiz->dir->numero;
            Raiz->freq = Raiz->dir->freq;
            Raiz->dir->numero = tpnum;
            Raiz->dir->freq = tpfreq;
        }

        else
        {
            ValidarArvoreDir(Raiz->dir);
        }
    }
}
