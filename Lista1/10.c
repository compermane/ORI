#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGHT 100

int main()
{
    FILE *cidades, *saida;
    char arq[20];
    char cidade[40];
    char maiorC[40];
    char linha[MAX_LENGHT];
    char *token;
    int pop, maior = 0;

    printf("Digite o arquivo de cidades a ser lido: ");
    scanf("%s", arq);

    cidades = fopen(arq, "r");
    if(cidades == NULL)
    {
        printf("O arquivo nao existe!");
        return 1;
    }

    saida = fopen("saida_10.txt", "w");

    while(fgets(linha, MAX_LENGHT, cidades) != NULL)
    {
        token = strtok(linha, "#");
        strcpy(cidade, token);

        token = strtok(NULL, "#");
        pop = atoi(token);

        if(pop > maior)
        {
            maior = pop;
            strcpy(maiorC, cidade);
        }
    }

    fprintf(saida, "%d %s", maior, maiorC);

    fclose(cidades);
    fclose(saida);

    return 0;

}