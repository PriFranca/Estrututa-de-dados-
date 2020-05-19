//Bibliotecas
#include <stdio.h> // Linhas 1 a 4. Inclusão de bibliotecas necessárias para o funcionamento do programa.
#include <stdlib.h>
#include <locale.h>

//Constantes. Linhas 6 e 7. Definição de constante para o tamanho da pilha.
#define tamanho 5

//Estrutura da Fila. Linhas 9 a 14. Registro de estrutura para criar o “tipo ila” contando com um vetor para armazenar os dados e dois números inteiros para controlar o início e fim da fila.
struct tfila {
int dados[tamanho];
int ini;
int fim;
};

//Variáveis globais. Linhas 16 a 18. Definições de variáveis.
struct tfila fila;
int op;

//Protipação. Linhas 20 a 24. Prototipação das funções. Para mais detalhes sobre prototipação, consulte o livro de Algoritmos e Lógica de Programação II.
void fila_entrar();
void fila_sair();
void fila_mostrar();
void menu_mostrar();

//Função principal. Linhas 26 a 47. Função principal (main), a primeira que será invocada na execução do programa.
int main(){
setlocale(LC_ALL, "Portuguese"); //Linha 28. Chamada de função para conigurar o idioma para português, permitindo o uso de acentos (não funciona em todas as versões do Windows).
op = 1; // Linhas 29 a 31. Inicialização das variáveis.
fila.ini = 0;
fila.fim = 0;
while (op != 0) { // Linhas 32 a 45. Laço principal, que será executado repetidamente até que o usuário decida inalizar o programa.
system("cls"); // Linha 33 Chamada de comando no sistema operacional para limpar a tela.
fila_mostrar(); // Linha 34 Chamada da função que mostra o conteúdo da Fila na tela.
menu_mostrar(); // Linha 35 Chamada da função que desenha o menu de opções.
scanf("%d", &op); // Linha 36 Lê a opção escolhida pelo usuário.
switch (op) { // Linhas 37 a 44. Desvio condicional, que faz chamada de acordo com a opção escolhida pelo usuário.
case 1:
fila_entrar();
break;
case 2:
fila_sair();
break;
}
}
return(0);
}

//Adicionar um elemento no final da Fila. Linhas 49 a 60. Função fila_entrar(), que faz checagem do fim da fila e insere novos valores no vetor dados.
void fila_entrar(){
if (fila.fim == tamanho) {
printf("\nA fila está cheia, volte outro dia!\n\n");
system("pause");
}
else {
printf("\nDigite o valor a ser inserido: ");
scanf("%d", &fila.dados[fila.fim]);
fila.fim++;
}
}

//Retirar o primeiro elemento da Fila. Linhas 62 a 76. Função fila_sair(), que veriica se existem elementos na fila e remove o elemento mais antigo.
void fila_sair() {
if (fila.ini == fila.fim) {
printf("\nFila vazia, mas logo aparece alguém!\n\n");
system("pause");
}
else {
int i;
for (i = 0; i < tamanho; i++) {
fila.dados[i] = fila.dados[i+1];
}
fila.dados[fila.fim] = 0;
fila.fim--;
}
}

//Mostrar o conteúdo da Fila. Linhas 78 a 86. Função fila_mostrar(), que lê o conteúdo e desenha o vetor dados na tela.
void fila_mostrar() {
int i;
printf("[ ");
for (i = 0; i < tamanho; i++) {
printf("%d ", fila.dados[i]);
}
printf("]\n\n");
}

//Mostrar o menu de opções. Linhas 88 a 94. Função menu_mostrar(), que desenha na tela as opções permitidas para o usuário.
void menu_mostrar() {
printf("\nEscolha uma opção:\n");
printf("1 - Incluir na Fila\n");
printf("2 - Excluir da Fila\n");
printf("0 - Sair\n\n");
}
