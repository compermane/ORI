#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *entrada, *saida;

    char arq[20];
    char c, aux;

    printf("Digite o arquivo a ser lido: ");
    scanf("%s", arq);

    entrada = fopen(arq, "r");
    if(entrada == NULL)
    {
        printf("Arquivo nao encontrado!");
        return 1;
    }

    saida = fopen("saida_7.txt", "w");

    while((c = fgetc(entrada)) != EOF)
    {
        aux = toupper(c);
        printf("%c", c);
        if(aux == 'A' || aux == 'E' || aux == 'I' || aux == 'O' || aux == 'U')
            fputc('*', saida);
        else
            fputc(c, saida);
    }

    fclose(entrada);
    fclose(saida);
}