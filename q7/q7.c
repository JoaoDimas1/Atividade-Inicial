#include <stdio.h>

#define MAX 100

struct Aluno {
    char nome[50];
    int matricula;
    float media;
};

int main() {
    struct Aluno alunos[MAX];
    int n, i;

    FILE *aprovados, *reprovados;

    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        printf("Nome: ");
        getchar(); 
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);

        printf("Matrícula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Média: ");
        scanf("%f", &alunos[i].media);
    }

    aprovados = fopen("aprovados.txt", "w");
    reprovados = fopen("reprovados.txt", "w");

    if (aprovados == NULL || reprovados == NULL) {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    fprintf(aprovados, "Alunos aprovados (média >= 7.0):\n\n");
    fprintf(reprovados, "Alunos reprovados (média < 7.0):\n\n");

    printf("\nResultados:\n");

    for (i = 0; i < n; i++) {
        if (alunos[i].media >= 7.0) {
            printf("✅ Aprovado: %s", alunos[i].nome);
            fprintf(aprovados, "Nome: %s", alunos[i].nome);
            fprintf(aprovados, "Matrícula: %d\n", alunos[i].matricula);
            fprintf(aprovados, "Média: %.2f\n\n", alunos[i].media);
        } else {
            printf("❌ Reprovado: %s", alunos[i].nome);
            fprintf(reprovados, "Nome: %s", alunos[i].nome);
            fprintf(reprovados, "Matrícula: %d\n", alunos[i].matricula);
            fprintf(reprovados, "Média: %.2f\n\n", alunos[i].media);
        }
    }

    fclose(aprovados);
    fclose(reprovados);

    printf("\nDados salvos em 'aprovados.txt' e 'reprovados.txt'.\n");

    return 0;
}
