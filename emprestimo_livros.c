#include <stdio.h>
#include <string.h>
#include <locale.h>


void process_field(int field_count, char *value) {
  if (field_count == 0) {
        printf("id_emprestimo:\t");
    }
    if (field_count == 1 ) {
        printf("codigo_barras:\t");
    }
    if (field_count == 2) {
            printf("data_renovacao:\t");
    }
    if (field_count == 3) {
        printf("data_emprestimo:\t");
    }
    if (field_count == 4) {
        printf("data_devolucao:\t");
    }
    if (field_count == 5) {
        printf("matricula_ou_siape:\t");
    }
    if (field_count == 6) {
        printf("nome_usuario:\t");
    }
    if (field_count == 7) {
        printf("tipo_vinculo_usuario :\t");
    }
   
    printf("%s\n\n", value);
}

int main(void) {
    char buf[1024];
    char token[1024];

    int row_count = 0;
    int field_count = 0;
    int in_double_quotes = 0;
    int token_pos = 0;
    int i = 0;
	
	setlocale(LC_ALL,"portuguese");
		
    FILE *fp = fopen("sample1.csv", "r");

    if (!fp) {
        printf("Não é possivel abrir o arquivo!\n");
        return 0;
    }


    while (fgets(buf, 1024, fp)) {
        row_count++;

        if (row_count == 1) {
            continue;
        }

        field_count = 0;
        i = 0;
        do {
            token[token_pos++] = buf[i];

            if (!in_double_quotes && (buf[i] == ',' || buf[i] == '\n')) {
                token[token_pos - 1] = 0;
                token_pos = 0;
                process_field(field_count++, token);
            }

            if (buf[i] == '"' && buf[i + 1] != '"') {
                token_pos--;
                in_double_quotes = !in_double_quotes;
            }

            if (buf[i] == '"' && buf[i + 1] == '"')
                i++;

        } while (buf[++i]);

        printf("\n");
    }

    fclose(fp);

    return 0;
}
