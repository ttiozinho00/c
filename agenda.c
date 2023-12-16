# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
#include <locale.h>

typedef struct
{
	char nome[31];
	char fone[21];
} pessoa;

int menu(void);
void incluir(void);
void listar(void);
void consultar(void);
void excluir(void);

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	while(1)
	{
		switch(menu())
		{
			case 1: incluir(); break;
			case 2: listar(); break;
			case 3: consultar(); break;
			case 4: excluir(); break;
			case 5: exit(0);
		}
	}
	return 0;
}

// Menu

int menu(void)
{
	int op;
	
	puts ("\n1 - Incluir");
	puts ("2 - Listar");
	puts ("3 - Consultar");
	puts ("4 - Excluir");
	puts ("5 - Sair");
	printf ("\n Opção:");
	scanf ("%d%*c", &op);
	return op;
}

// Incluir

void incluir(void)
{
	FILE *s;
	pessoa p;
	
	s = fopen ("agenda.dat", "ab");
	
	if (s==NULL)
	{
		puts("erro fatal: o arquivo nao pode ser aberto!!!");
		exit(1);
	}

	printf("\nNome: ");
	fgets(p.nome, sizeof(p.nome), stdin);
	printf("Fone:");
	fgets(p.fone, sizeof(p.fone), stdin);
	fwrite (&p, sizeof(pessoa),1 ,s);
	printf("\nRegistro gravado!!!\n");
	fclose(s);
}

// Listar

void listar(void)
{
	FILE *s;
	pessoa p;
	
	s = fopen ("agenda.dat", "rb");
	
	if (s==NULL)
	{
		puts ("erro fatal: o arquivo nao pode ser aberto!!!");
		exit (2);
	}

	while (1)
	{
		fread (&p, sizeof(pessoa), 1,s);

		if (feof(s))
		{
			printf("\n%s %s", p.nome, p.fone);
			break;
		}
	}
	printf("\n\n");
	fclose(s);
}

//Consultar

/*int strcmp (char a[], char b[])
{
	int i =0;
	
	while ((toupper(a[i]) == toupper(b[i])) && (a[i] != '\0'))
	{
		i++;
	}
	return a[i]-b[i];
}*/

void consultar(void)
{
	FILE *s;
	pessoa p;
	char n[31];
	int t=0;
	
	s = fopen("agenda.dat"," rb");
	
	if (s==NULL)
	{
		puts ("erro fatal: o arquivo nao pode ser aberto!!!");
		exit (3);
	}
	printf ("\nNome: ");
	fgets(n, sizeof(n), stdin);


	while (1)
	{
		fread (&p, sizeof(pessoa), 1, s);

		if (feof(s))
		{
			break;
		}

		if (strcmp (n, p.nome) == 0)
		{
			printf("\nFone: %s", p.fone);
			t++;
		}
	}
	printf("\nRegistro(s) encontrado(s): %d\n", t);
	fclose(s);
}

// Excluir

void excluir (void)
{
	{
		FILE *e, *s;
		pessoa p;
		char n[31];
		int t=0;
		
		remove ("agenda.bak");
		rename ("agenda.dat","agenda.bak");
		
		e = fopen ("agenda.bak","rb");
		
		if (e == NULL)
		{
			puts("erro fatal: o arquivo nao pode ser aberto!!!");
			exit (4);
		}
		
		s = fopen("agenda.dat","wb");
		
		if(s==NULL)
		{
			puts ("erro fatal: o arquivo não pode ser aberto!!!");
			exit(5);
		}
		
		printf("\nNome: ");
		fgets(n, sizeof(n), stdin);
		
		while(1)
		{
			fread (&p, sizeof(pessoa), 1, e);

			if(feof(e))
			{
				break;
			}

			if(strcmp(n,p.nome) != 0)
			{
				
				fwrite(&p, sizeof(pessoa),1,s);
			}

			else
			{
				t++;
			}
		}
		printf("Registro(s) excluido(s): %d\n\n", t);
		fclose (e);
		fclose (s);
	}
}	