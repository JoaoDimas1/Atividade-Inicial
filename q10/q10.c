#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    printf("Digite a posição n (n >= 0): ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Por favor, digite um número não negativo.\n");
    } else {
        printf("Fibonacci de %d é %d\n", n, fibonacci(n));
    }

    return 0;
}
