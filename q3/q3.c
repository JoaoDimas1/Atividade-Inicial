#include <stdio.h>

int inverterNumero(int n) {
    int invertido = 0;
    while (n > 0) {
        invertido = invertido * 10 + (n % 10);
        n = n / 10;
    }
    return invertido;
}

int main() {
    int numero;

    printf("Digite um número inteiro positivo: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Número negativo não é suportado.\n");
    } else {
        int resultado = inverterNumero(numero);
        printf("Número invertido: %d\n", resultado);
    }

    return 0;
}
