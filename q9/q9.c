#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contato {
    char nome[50];
    char telefone[20];
    char email[50];
};

// Protótipos
void salvar(struct Contato agenda[], int total);
int carregar(struct Contato agenda[]);

int main() {
    struct Contato agenda[MAX];
    int total = carregar(agenda);
    int opcao;

    do {
        printf("\n--- AGENDA ---\n");
        printf("1. Adicionar contato\n");
        printf("2. Buscar por nome\n");
        printf("3. Exibir todos os contatos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (total < MAX) {
                printf("\n--- Novo Contato ---\n");
                getchar(); 
                printf("Nome: ");
                fgets(agenda[total].nome, sizeof(agenda[total].nome), stdin);
                printf("Telefone: ");
                fgets(agenda[total].telefone, sizeof(agenda[total].telefone), stdin);
                printf("Email: ");
                fgets(agenda[total].email, sizeof(agenda[total].email), stdin);

                total++;
                salvar(agenda, total);
                printf("Contato adicionado!\n");
            } else {
                printf("Agenda cheia!\n");
            }

        } else if (opcao == 2) {
            char busca[50];
            int encontrado = 0;
            getchar(); 
            printf("\nDigite o nome a buscar: ");
            fgets(busca, sizeof(busca), stdin);

            printf("\n--- Resultados ---\n");
            for (int i = 0; i < total; i++) {
                if (strstr(agenda[i].nome, busca) != NULL) {
                    printf("Nome: %s", agenda[i].nome);
                    printf("Telefone: %s", agenda[i].telefone);
                    printf("Email: %s\n", agenda[i].email);
                    encontrado = 1;
                }
            }

            if (!encontrado) {
                printf("Contato não encontrado.\n");
            }

        } else if (opcao == 3) {
            printf("\n--- Todos os Contatos ---\n");
            for (int i = 0; i < total; i++) {
                printf("Contato %d:\n", i + 1);
                printf("Nome: %s", agenda[i].nome);
                printf("Telefone: %s", agenda[i].telefone);
                printf("Email: %s\n", agenda[i].email);
            }
            if (total == 0) {
                printf("Nenhum contato cadastrado.\n");
            }

        } else if (opcao != 0) {
            printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    printf("Encerrando a agenda.\n");
    return 0;
}

void salvar(struct Contato agenda[], int total) {
    FILE *f = fopen("agenda.txt", "w");
    if (f == NULL) {
        printf("Erro ao salvar.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(f, "%s%s%s", agenda[i].nome, agenda[i].telefone, agenda[i].email);
    }

    fclose(f);
}

int carregar(struct Contato agenda[]) {
    FILE *f = fopen("agenda.txt", "r");
    int i = 0;
    if (f == NULL) return 0;

    while (i < MAX &&
        fgets(agenda[i].nome, sizeof(agenda[i].nome), f) != NULL &&
        fgets(agenda[i].telefone, sizeof(agenda[i].telefone), f) != NULL &&
        fgets(agenda[i].email, sizeof(agenda[i].email), f) != NULL) {
        i++;
    }

    fclose(f);
    return i;
}
