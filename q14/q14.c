#include <stdio.h>
#include <string.h>

void cifraDeCesar(char mensagem[], int deslocamento) {
    for (int i = 0; mensagem[i] != '\0'; i++) {
        char c = mensagem[i];

        if (c >= 'A' && c <= 'Z') {
            mensagem[i] = ((c - 'A' + deslocamento) % 26) + 'A';
        }
        
        else if (c >= 'a' && c <= 'z') {
            mensagem[i] = ((c - 'a' + deslocamento) % 26) + 'a';
        }

    }
}

int main() {
    char mensagem[100];
    int deslocamento;

    printf("Digite a mensagem: ");
    fgets(mensagem, sizeof(mensagem), stdin);

    printf("Digite o deslocamento: ");
    scanf("%d", &deslocamento);

    cifraDeCesar(mensagem, deslocamento);

    printf("Mensagem criptografada: %s\n", mensagem);

    return 0;
}
