#include <stdio.h>

int buscaBinaria(int vetor[], int tamanho, int alvo) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vetor[meio] == alvo) {
            return meio; 
        } else if (vetor[meio] < alvo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1; 
}

int main() {
    int vetor[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}; 
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int alvo;

    printf("Digite o número a buscar: ");
    scanf("%d", &alvo);

    int resultado = buscaBinaria(vetor, tamanho, alvo);

    if (resultado != -1) {
        printf("Elemento encontrado na posição %d.\n", resultado);
    } else {
        printf("Elemento não encontrado.\n");
    }

    return 0;
}
