#include <stdio.h>

int main() {
    int A[3][3], B[3][3], soma[3][3];
    int i, j;

    printf("Digite os valores da matriz A (3x3):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nDigite os valores da matriz B (3x3):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            soma[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nMatriz Soma (A + B):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%4d", soma[i][j]);
        }
        printf("\n");
    }

    return 0;
}
