#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char palavraSecreta[] = "computador";  
    char letra;
    int chances = 6;
    int acertos = 0;
    int tamanho = strlen(palavraSecreta);
    char palavraAdivinhada[30];

    
    for (int i = 0; i < tamanho; i++) {
        palavraAdivinhada[i] = '_';
    }
    palavraAdivinhada[tamanho] = '\0'; 

    printf("=== Jogo da Forca ===\n");

    while (chances > 0 && acertos < tamanho) {
        printf("\nPalavra: ");
        for (int i = 0; i < tamanho; i++) {
            printf("%c ", palavraAdivinhada[i]);
        }

        printf("\nTentativas restantes: %d", chances);
        printf("\nDigite uma letra: ");
        scanf(" %c", &letra);
        letra = tolower(letra); 

        int acertou = 0;
        for (int i = 0; i < tamanho; i++) {
            if (palavraSecreta[i] == letra && palavraAdivinhada[i] == '_') {
                palavraAdivinhada[i] = letra;
                acertos++;
                acertou = 1;
            }
        }

        if (!acertou) {
            chances--;
            printf("Letra incorreta!\n");
        } else {
            printf("Boa! Letra correta.\n");
        }
    }

    if (acertos == tamanho) {
        printf("\nParabéns! Você venceu. A palavra era: %s\n", palavraSecreta);
    } else {
        printf("\nVocê perdeu! A palavra era: %s\n", palavraSecreta);
    }

    return 0;
}
