#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX_LENGHT 100
#define NAME_MAX_LENGHT 40

void bubbleSort(double* v, char** nomes, int n)
{
    int i = n - 1;
    int j = 1;
    int aux;
    char nomeAux[40];

    while(i > 1)
    {
        while(j <= i)
        {
            if(v[j - 1] > v[j])
            {
                aux = v[j];
                strcpy(nomeAux, nomes[j]);
                v[j] = v[j - 1];
                strcpy(nomes[j], nomes[j - 1]);
                v[j - 1] = aux;
                strcpy(nomes[j - 1], nomeAux);
            }
            j++;
        }
        j = 1;
        i--;
    }
}

int main()
{
    FILE *entrada = fopen("entrada_22.txt", "r");
    FILE *saida = fopen("saida_22.txt", "w");
    char linha[LINE_MAX_LENGHT];
    char *nome[3];
    double notas[3];
    int i = 0;

    while(fgets(linha, LINE_MAX_LENGHT, entrada) != NULL)
    {
        printf("BRUH3\n");
        sscanf(linha, "%s %lf %lf %lf", nome[i], &notas[0], &notas[1], &notas[2]);
        i++;
    }
    printf("BRUH2");
    bubbleSort(notas, nome, 3);
    printf("BRUH1\n");
    for(int j = 0; j < i + 1; j++)
        fprintf(saida, "%s %.2lf %.2lf %.2lf", nome[i], notas[0], notas[1], notas[2]);

    fclose(entrada);
    fclose(saida);

    return 0;
}