//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // Linhas 1 a 4 Inclusão de bibliotecas necessárias para o funcionamento do programa. 

//Constantes
#define tamanho 5 // Linhas 6 e 7 Definição de constante para o tamanho da pilha.

//Estrutura da Pilha Linhas 9 a 14
//Registro de estrutura para criar o “tipo pilha” contando com um vetor para armazena os dados e dois números inteiros para controlar o início e fim da pilha
struct tpilha {
int dados[tamanho];
int ini;
int fim;
};

//Variáveis globais. Linhas 16 a 18 Deinições de variáveis
struct tpilha pilha;
int op;

//Protipação. Linhas 20 a 24 Prototipação das funções. Para mais detalhes sobre prototipação, consulte o livro de Algoritmos e Lógica de Programação II.
void pilha_entrar();
void pilha_sair();
void pilha_mostrar();
void menu_mostrar();
//Função principal. Linhas 26 a 47 Função principal (main), a primeira que será invocada na execução do programa.
int main(){
setlocale(LC_ALL, "Portuguese"); //Linha 28 Chamada de função para conigurar o idioma para português, permitindo o uso de acentos (não funciona em todas as versões do Windows).
op = 1; // Linhas 29 a 31 Inicialização das variáveis.
pilha.ini = 0;
pilha.fim = 0;
while (op != 0) { // Linhas 32 a 45 Laço principal, que será executado repetidamente até que o usuário decida finalizar o programa.
system("cls"); // Linha 33 Chamada de comando no sistema operacional para limpar a tela.
pilha_mostrar(); // Linha 34 Chamada da função que mostra o conteúdo da Pilha na tela.
menu_mostrar(); // Linha 35 Chamada da função que desenha o menu de opções.
scanf("%d", &op); // Linha 36 Lê a opção escolhida pelo usuário.
switch (op) { // Linhas 37 a 44 Desvio condicional, que faz chamada de acordo com a opção escolhida pelo usuário.
case 1:
pilha_entrar();
break ;
case 2:
pilha_sair();
break;
}
}
return(0);
}
//Adicionar um elemento no final da Pilha.  Linhas 49 a 60 Função pilha_entrar(), que faz checagem do topo da pilha e insere novos valores no vetor dados.
void pilha_entrar(){
if (pilha.fim == tamanho) {
printf("\nA pilha está cheia, impossível empilhar!\n\n");
system("pause");
}
else {
printf("\nDigite o valor a ser empilhado: ");
scanf("%d", &pilha.dados[pilha.fim]);
pilha.fim++;
}
}

//Retirar o último elemento da Pilha
void pilha_sair() { // Linhas 62 a 72 Função pilha_sair(), que veriica se existem elementos na pilha e remove o último inserido.
if (pilha.ini == pilha.fim)
 {
printf("\nA pilha está vazia, impossível desempilhar!\n\n");
system("pause");
}
else {
pilha.dados[pilha.fim-1] = 0;
pilha.fim--;
}
}

//Mostrar o conteúdo da Pilha. Linhas 74 a 82 Função pilha_mostrar(), que lê o conteúdo e desenha o vetor dados na tela.
void pilha_mostrar() {
int i;
printf("[ ");
for (i = 0; i < tamanho; i++) {
printf("%d ", pilha.dados[i]);
}
printf("]\n\n");
}

//Mostrar o menu de opções. Linhas 84 a 90 Função menu_mostrar(), que desenha na tela as opções permitidas para o usuário.
void menu_mostrar() {
	printf("1 - Empilhar\n");
printf("2 - Desempilhar\n");
printf("0 - Sair\n\n");
}
