#include <stdio.h>

int Primo(int n) {
    if (n <= 1)
        return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int inicio, fim;

    printf("Digite o numero inicial: ");
    scanf("%d", &inicio);
    printf("Digite o numero final: ");
    scanf("%d", &fim);

    printf("Numeros primos entre %d e %d:\n", inicio, fim);
    for (int i = inicio; i <= fim; i++) {
        if (Primo(i))
            printf("%d ", i);
    }

    printf("\n");
    return 0;
}