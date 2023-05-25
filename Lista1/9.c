#include <stdio.h>

int main()
{
    FILE *entrada1, *entrada2, *saida;
    char c;
    char arq1[20], arq2[20];

    printf("Digite o nome do primeiro arquivo: ");
    scanf("%s", arq1);

    printf("Digite o nome do segundo arquivo: ");
    scanf("%s", arq2);

    entrada1 = fopen(arq1, "r");
    entrada2 = fopen(arq2, "r");

    if(entrada1 == NULL || entrada2 == NULL)
    {
        printf("Pelo menos um dos arquivos informados não existe!");
        return 1;
    }

    saida = fopen("saida_9.txt", "w");

    while((c = fgetc(entrada1)) != EOF)
        fputc(c, saida);

    fputc('\n', saida);

    while((c = fgetc(entrada2)) != EOF)
        fputc(c, saida);

    fclose(entrada1);
    fclose(entrada2);
    fclose(saida);

    return 0;
}