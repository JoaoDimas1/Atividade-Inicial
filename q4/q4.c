#include <stdio.h>

int main() {
    int numeros[10];
    int i, j;
    
    printf("Digite 10 números inteiros:\n");
    for (i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("\nFrequência dos números:\n");
    for (i = 0; i < 10; i++) {
        int count = 1;
        int jaContado = 0;

        for (j = 0; j < i; j++) {
            if (numeros[i] == numeros[j]) {
                jaContado = 1;
                break;
            }
        }

        if (!jaContado) {
            for (j = i + 1; j < 10; j++) {
                if (numeros[i] == numeros[j]) {
                    count++;
                }
            }
            printf("%d aparece %d vez(es)\n", numeros[i], count);
        }
    }

    return 0;
}
