#include <stdio.h>
#include <string.h>

#define MAX 100

struct Produto {
    char nome[50];
    int codigo;
    int quantidade;
    float preco;
};


void salvar(struct Produto estoque[], int total);
int carregar(struct Produto estoque[]);

int main() {
    struct Produto estoque[MAX];
    int total = carregar(estoque);
    int opcao;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Cadastrar produto\n");
        printf("2. Buscar produto por código\n");
        printf("3. Listar produtos\n");
        printf("4. Editar produto\n");
        printf("5. Remover produto\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (total < MAX) {
                printf("\n--- Cadastro ---\n");
                printf("Nome: ");
                getchar(); 
                fgets(estoque[total].nome, sizeof(estoque[total].nome), stdin);

                printf("Código: ");
                scanf("%d", &estoque[total].codigo);

                printf("Quantidade: ");
                scanf("%d", &estoque[total].quantidade);

                printf("Preço: ");
                scanf("%f", &estoque[total].preco);

                total++;
                salvar(estoque, total);
                printf("Produto cadastrado com sucesso!\n");
            } else {
                printf("Estoque cheio!\n");
            }

        } else if (opcao == 2) {
            int cod, i, ok = 0;
            printf("\nDigite o código do produto: ");
            scanf("%d", &cod);
            for (i = 0; i < total; i++) {
                if (estoque[i].codigo == cod) {
                    printf("\nProduto encontrado:\n");
                    printf("Nome: %s", estoque[i].nome);
                    printf("Código: %d\n", estoque[i].codigo);
                    printf("Quantidade: %d\n", estoque[i].quantidade);
                    printf("Preço: R$ %.2f\n", estoque[i].preco);
                    ok = 1;
                    break;
                }
            }
            if (!ok) printf("Produto não encontrado.\n");

        } else if (opcao == 3) {
            if (total == 0) {
                printf("\nNenhum produto cadastrado.\n");
            } else {
                printf("\n--- Lista de Produtos ---\n");
                for (int i = 0; i < total; i++) {
                    printf("Produto %d:\n", i + 1);
                    printf("Nome: %s", estoque[i].nome);
                    printf("Código: %d\n", estoque[i].codigo);
                    printf("Quantidade: %d\n", estoque[i].quantidade);
                    printf("Preço: R$ %.2f\n\n", estoque[i].preco);
                }
            }

        } else if (opcao == 4) {
            int cod, i, ok = 0;
            printf("\nDigite o código do produto a editar: ");
            scanf("%d", &cod);
            for (i = 0; i < total; i++) {
                if (estoque[i].codigo == cod) {
                    printf("Novo nome: ");
                    getchar();
                    fgets(estoque[i].nome, sizeof(estoque[i].nome), stdin);
                    printf("Nova quantidade: ");
                    scanf("%d", &estoque[i].quantidade);
                    printf("Novo preço: ");
                    scanf("%f", &estoque[i].preco);
                    salvar(estoque, total);
                    printf("Produto atualizado!\n");
                    ok = 1;
                    break;
                }
            }
            if (!ok) printf("Produto não encontrado.\n");

        } else if (opcao == 5) {
            int cod, i, j, ok = 0;
            printf("\nDigite o código do produto a remover: ");
            scanf("%d", &cod);
            for (i = 0; i < total; i++) {
                if (estoque[i].codigo == cod) {
                    for (j = i; j < total - 1; j++) {
                        estoque[j] = estoque[j + 1];
                    }
                    total--;
                    salvar(estoque, total);
                    printf("Produto removido.\n");
                    ok = 1;
                    break;
                }
            }
            if (!ok) printf("Produto não encontrado.\n");

        } else if (opcao != 0) {
            printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    printf("Encerrando o programa.\n");
    return 0;
}

void salvar(struct Produto estoque[], int total) {
    FILE *f = fopen("estoque.txt", "w");
    if (f == NULL) {
        printf("Erro ao salvar no arquivo.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(f, "%s%d\n%d\n%.2f\n", estoque[i].nome, estoque[i].codigo, estoque[i].quantidade, estoque[i].preco);
    }

    fclose(f);
}

int carregar(struct Produto estoque[]) {
    FILE *f = fopen("estoque.txt", "r");
    int i = 0;

    if (f == NULL) {
        return 0; 
    }

    while (i < MAX && fgets(estoque[i].nome, sizeof(estoque[i].nome), f) != NULL) {
        fscanf(f, "%d\n", &estoque[i].codigo);
        fscanf(f, "%d\n", &estoque[i].quantidade);
        fscanf(f, "%f\n", &estoque[i].preco);
        i++;
    }

    fclose(f);
    return i;
}
