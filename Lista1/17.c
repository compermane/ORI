#include <stdio.h>

#define LINE_MAX_LENGHT 100

int main()
{
    FILE *entrada = fopen("matriz.txt", "r");
    FILE *saida = fopen("17_saida.txt", "w");
    char linha[LINE_MAX_LENGHT];
    int linhas, colunas, qtd;

    while(fgets(linha, LINE_MAX_LENGHT, entrada) != NULL)
    {
        sscanf(linha, "%d %d %d", &linhas, &colunas, &qtd);
        int linhaAlvo[qtd], colunaAlvo[qtd];

        for(int k = 0; k < qtd; k++)
        {
            fgets(linha, LINE_MAX_LENGHT, entrada);
            printf("%s", linha);
            sscanf(linha, "%d %d", &linhaAlvo[k], &colunaAlvo[k]);
        }

        int count = 0;
        for(int i = 0; i < linhas; i++)
        {
            for(int j = 0; j < colunas; j++)
            {
                if(count < qtd)
                {
                    if(i == linhaAlvo[count] && j == colunaAlvo[count])
                    {
                        fprintf(saida, "0 ");
                        count++;
                    }
                    else
                        fprintf(saida, "1 ");
                }
                else
                {
                    printf("BRUH");
                    fprintf(saida, "1 ");
                }
            }
            fprintf(saida, "\n");
        }

        fprintf(saida, "\n");
    }
    fclose(saida);
    fclose(entrada);
}