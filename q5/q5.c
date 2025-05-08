#include <stdio.h>

int main() {
    int A[5], B[5];
    int i, j;

    printf("Digite 5 números para o vetor A:\n");
    for (i = 0; i < 5; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    printf("\nDigite 5 números para o vetor B:\n");
    for (i = 0; i < 5; i++) {
        printf("B[%d]: ", i);
        scanf("%d", &B[i]);
    }

    printf("\nElementos comuns entre A e B:\n");
    for (i = 0; i < 5; i++) {
        int comum = 0;

        // Verifica se A[i] está em B
        for (j = 0; j < 5; j++) {
            if (A[i] == B[j]) {
                comum = 1;
                break;
            }
        }

        if (comum) {
            int jaMostrado = 0;
            for (j = 0; j < i; j++) {
                if (A[i] == A[j]) {
                    jaMostrado = 1;
                    break;
                }
            }

            if (!jaMostrado)
                printf("%d\n", A[i]);
        }
    }

    return 0;
}
