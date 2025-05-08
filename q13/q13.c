#include <stdio.h>

int main() {
    int matriz[4][4];
    int soma = 0;

    printf("Digite os elementos da matriz 4x4:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < 4; i++) {
        soma += matriz[i][i];
    }

    
    printf("Soma da diagonal principal: %d\n", soma);

    return 0;
}
