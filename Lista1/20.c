#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_MAX_LENGHT 100
#define NAME_MAX_LENGHT 40

int main()
{
    FILE *saida = fopen("saida_20.txt", "w");
    int qtd;
    char nome[NAME_MAX_LENGHT];

    printf("Digite a quantidade de alunos na sala: ");
    scanf("%d", &qtd);

    char **alunos = malloc(qtd * sizeof(char));
    double *notas = (double*) malloc(qtd * sizeof(double));

    for(int i = 0; i < qtd; i++)
    {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", nome);
        alunos[i] = malloc(NAME_MAX_LENGHT * sizeof(char));
        strcpy(alunos[i], nome);
        
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%lf", &notas[i]);
    }

    for(int j = 0; j < qtd; j++)
        fprintf(saida, "Nome: %s, Nota: %.2lf\n", alunos[j], notas[j]);

    free(alunos);
    free(notas);
    fclose(saida);
    return 0;
}