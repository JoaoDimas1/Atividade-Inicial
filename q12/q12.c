#include <stdio.h>
#include <string.h>

int ehPalindromo(char str[]) {
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j) {
        if (str[i] != str[j]) {
            return 0; 
        }
        i++;
        j--;
    }

    return 1; 
}

int main() {
    char palavra[100];

    printf("Digite uma palavra: ");
    fgets(palavra, sizeof(palavra), stdin);
    
    palavra[strcspn(palavra, "\n")] = '\0';

    if (ehPalindromo(palavra)) {
        printf("É um palíndromo!\n");
    } else {
        printf("Não é um palíndromo.\n");
    }

    return 0;
}
