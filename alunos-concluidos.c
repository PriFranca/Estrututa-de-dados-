#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define BSIZE 1000

typedef struct registro
{
	int matricula;
	char nome[50]; 
	char curso[40];
	int ano;
	char campus[10];
}registro;

registro dados [1024];

void process_field(int field_count, char *value,int i)
{
    if (field_count  == 0)
	{
	    dados[i].matricula = atoi(value);
    }
    if (field_count  == 1)
	{
		 strcpy(dados[i].nome,value);;
    }
    if (field_count  == 2)
	{
		 strcpy(dados[i].curso,value);
    }
     
    if (field_count  == 3)
	{
	    dados[i].ano = atoi(value);
    }
    if (field_count  == 4)
	{
		strcpy(dados[i].campus,value);
    }
    

}
void imprimir (int row_count)
{
    int i;
    for(i=0; i <= row_count-2; i++)
	{
        printf("Matricula:%d\n",dados[i].matricula);
        printf("Nome:\t%s\n",dados[i].nome);
        printf("Curso:\t%s\n",dados[i].curso); 
        printf("Ano:\t%d\n",dados[i].ano);
		printf("Campus:\t%d\n",dados[i].campus); 
        printf("\n");

    }

}

//função genérica de troca de valores//
void troca (registro* a, registro* b)
{
	registro tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

//Aplicar método de ordenação bubblleSort//
int bubbleSort(registro vec[], int TAM)
{
	int i, j, tmp;
	for(i = 0; i < TAM; i++)
	{
		for(j = i+1; j < TAM; j++)
		{
			if (vec[i].matricula > vec[j].matricula)
			{
				troca (&vec[i],&vec[j]);

			}

		}

	}

}

int main(void)
{

	setlocale(LC_ALL, "Portuguese");
    char buf[1024];
    char token[1024];
	int row_count = 0;
    int field_count = 0;
    int in_double_quotes = 0;
    int token_pos = 0;
    int i = 0;

    FILE *fp = fopen("alunos.csv", "r");

    if (!fp)
	{
        printf("Can't open alunos\n");
        return 0;
    }


    while (fgets(buf, 1024, fp))
	{
        row_count++;

        if (row_count == 1)
		{
            continue;
        }

        field_count = 0;
        i = 0;
        do
		{
            token[token_pos++] = buf[i];

            if (!in_double_quotes && (buf[i] == ';' || buf[i] == '\n'))
			{
                token[token_pos - 1] = 0;
                token_pos = 0;
                process_field(field_count++, token,row_count-2);
            }

            if (buf[i] == '"' && buf[i + 1] != '"')
			{
                token_pos--;
                in_double_quotes = !in_double_quotes;
            }

            if (buf[i] == '"' && buf[i + 1] == '"')
                i++;

        } while (buf[++i]);

        printf("\n");
    }
    printf("Desordenado:\n\n");
    imprimir(row_count);
    printf("\n\n");

	bubbleSort(dados,row_count-1);

	printf("Metodo BubbleSort:\n\n");
    imprimir(row_count);
    printf("\n\n");

    fclose(fp);

    return 0;
}
