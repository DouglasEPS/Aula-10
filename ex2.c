#include <stdio.h>
#include <stdlib.h>

//PROTÓTIPOS
int *alocarVetor(int n);
void preencherVetor(int *vetor, int n, const char *nome);
int *concatenarVetores(int *v1, int n1, int *v2, int n2);
void exibirVetor(int *vetor, int n);
void liberarVetores(int *v1, int *v2, int *v3);


int main() {
    int n1, n2;
    int *v1, *v2, *v3;

    printf("Tamanho do primeiro vetor: ");
    scanf("%d", &n1);
    printf("Tamanho do segundo vetor: ");
    scanf("%d", &n2);

    v1 = alocarVetor(n1);
    v2 = alocarVetor(n2);

    preencherVetor(v1, n1, "primeiro");
    preencherVetor(v2, n2, "segundo");

    v3 = concatenarVetores(v1, n1, v2, n2);

    printf("\nVetor concatenado:\n");
    exibirVetor(v3, n1 + n2);

    liberarVetores(v1, v2, v3);

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

void preencherVetor(int *vetor, int n, const char *nome) {
    printf("\nPreencha o %s vetor:\n", nome);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }
}

int *concatenarVetores(int *v1, int n1, int *v2, int n2) {
    int *v3 = (int *)malloc((n1 + n2) * sizeof(int));
    if (v3 == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    for (int i = 0; i < n1; i++)
        v3[i] = v1[i];

    for (int i = 0; i < n2; i++)
        v3[n1 + i] = v2[i];

    return v3;
}

void exibirVetor(int *vetor, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

void liberarVetores(int *v1, int *v2, int *v3) {
    free(v1);
    free(v2);
    free(v3);
}
