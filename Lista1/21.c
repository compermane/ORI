#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX_LENGHT 40

typedef struct
{
    char nome[NAME_MAX_LENGHT];
    double nota;
} Aluno;

void ordenaNotas(Aluno* alunos, int n)
{
    int i = n - 1;
    int j = 1;
    Aluno aux;

    while(i > 1)
    {
        while(j <= i)
        {
            if(alunos[j].nota < alunos[j - 1].nota)
            {
                strcpy(aux.nome, alunos[j - 1].nome);
                aux.nota = alunos[j - 1].nota;
                strcpy(alunos[j - 1].nome, alunos[j].nome);
                alunos[j - 1].nota = alunos[j].nota;
                strcpy(alunos[j].nome, aux.nome);
                alunos[j].nota = aux.nota;
            }
            j++;
        }
        j = 1;
        i--;
    }
}

int main()
{
    FILE *saida = fopen("saida_21.txt", "w");
    int qtd;

    printf("Digite o numero de pessoas na sala: ");
    scanf("%d", &qtd);

    Aluno *alunos = (Aluno*) malloc(qtd * sizeof(Aluno));

    for(int i = 0; i < qtd; i++)
    {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);

        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%lf", &alunos[i].nota);
    }

    ordenaNotas(alunos, qtd);

    for(int i = 0; i < qtd; i++)
        fprintf(saida, "Nome: %s, Nota: %.2lf\n", alunos[i].nome, alunos[i].nota);

    free(alunos);
    fclose(saida);

    return 0;
}