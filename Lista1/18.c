#include <stdio.h>
#include <string.h>

#define LINE_MAX_LENGHT 100
#define NAME_MAX_LENGHT 40

int main()
{
    FILE *entrada = fopen("produtos.txt", "r");
    char nome[NAME_MAX_LENGHT];
    char linha[LINE_MAX_LENGHT];
    double preco, total = 0; 
    while(fgets(linha, LINE_MAX_LENGHT, entrada) != NULL)
    {
        sscanf(linha, "%s %lf", nome, &preco);
        total = total + preco;
    }
    printf("O preco total da compra eh: %.2lf", total);
    fclose(entrada);
    return 0;
}