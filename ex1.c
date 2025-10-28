#include <stdio.h>
#include <stdlib.h>

//PROTÓTIPOS
int *alocarVetor(int n);
void lerVetor(int *vetor, int n);
void exibirPares(int *vetor, int n);
void liberarVetor(int *vetor);


int main() {
    int n;
    int *vetor;

    printf("Quantos numeros voce quer digitar? ");
    scanf("%d", &n);

    vetor = alocarVetor(n);
    lerVetor(vetor, n);
    exibirPares(vetor, n);
    liberarVetor(vetor);

    return 0;
}

//FUNÇÕES

int *alocarVetor(int n) {
    int *vetor = (int *)malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    return vetor;
}

void lerVetor(int *vetor, int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

void exibirPares(int *vetor, int n) {
    printf("\nNumeros pares digitados:\n");
    for (int i = 0; i < n; i++) {
        if (vetor[i] % 2 == 0)
            printf("%d ", vetor[i]);
    }
    printf("\n");
}

void liberarVetor(int *vetor) {
    free(vetor);
}
