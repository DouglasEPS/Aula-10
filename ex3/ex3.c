#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//PROTÓTIPOS 
char **criarLista(int tamanhoInicial);
char **adicionarItem(char **lista, int *tamanho, int *count, const char *item);
void exibirLista(char **lista, int count);
void liberarLista(char **lista, int count);


int main() {
    int tamanho = 2; //começa com 2 itens
    int count = 0;
    char **lista;
    char item[100];
    char opcao;

    lista = criarLista(tamanho);

    do {
        printf("Digite um item da lista: ");
        scanf(" %[^\n]", item);

        lista = adicionarItem(lista, &tamanho, &count, item);

        printf("Adicionar outro item? (s/n): ");
        scanf(" %c", &opcao);

    } while (opcao == 's' || opcao == 'S');

    exibirLista(lista, count);
    liberarLista(lista, count);

    return 0;
}

//FUNÇÕES

char **criarLista(int tamanhoInicial) {
    char **lista = (char **)malloc(tamanhoInicial * sizeof(char *));
    if (lista == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    return lista;
}

char **adicionarItem(char **lista, int *tamanho, int *count, const char *item) {
    if (*count == *tamanho) {
        *tamanho *= 2; // dobra o tamanho
        lista = (char **)realloc(lista, *tamanho * sizeof(char *));
        if (lista == NULL) {
            printf("Erro ao realocar memoria!\n");
            exit(1);
        }
    }

    lista[*count] = (char *)malloc((strlen(item) + 1) * sizeof(char));
    strcpy(lista[*count], item);
    (*count)++;

    return lista;
}

void exibirLista(char **lista, int count) {
    printf("\nLista de compras:\n");
    for (int i = 0; i < count; i++)
        printf("%d. %s\n", i + 1, lista[i]);
}

void liberarLista(char **lista, int count) {
    for (int i = 0; i < count; i++)
        free(lista[i]);
    free(lista);
}
