#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_LENGHT 100

int main()
{
    FILE *entrada;
    char arq[20];
    char palavra[MAX_LENGHT];
    char linha[MAX_LENGHT];
    char *token;
    int count = 0;

    printf("Digite o arquivo a ser lido: ");
    scanf("%s", arq);

    printf("Digite a palavra a ser contada: ");
    scanf("%s", palavra);
    entrada = fopen(arq, "r");
    if(entrada == NULL)
    {
        printf("Arquivo não existe!");
        return 1;
    }

    while(fscanf(entrada, "%s", linha) != EOF)
        if(!(strcmp(linha, palavra)))
            count++;

    printf("A quantidade de vezes que a palavra '%s' aparece eh %d", palavra, count);

    fclose(entrada);

    return 0;
}