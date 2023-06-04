#include <stdio.h>
#include <string.h>
#include <time.h>

#define LINE_MAX_LENGHT 100
#define NAME_MAX_LENGHT 40

int calculaIdade(int anoAtual, int ano)
{
    return anoAtual - ano;
}

int main()
{
    FILE *entrada = fopen("datas.txt", "r");
    FILE *saida = fopen("saida_15.txt", "w");
    int anoAtual, ano, mes, dia, idade;
    char linha[LINE_MAX_LENGHT], nome[NAME_MAX_LENGHT];

    if(entrada == NULL)
    {
        printf("Nao foi possivel abrir o arquivo");
        return 1;
    }

    printf("Digite o ano atual: ");
    scanf("%d", &anoAtual);

    while(fgets(linha, LINE_MAX_LENGHT, entrada) != NULL)
    {
        if(linha[strlen(linha) - 1] == '\n')
            linha[strlen(linha) - 1] = '\0';
        
        sscanf(linha, "%s %d %d %d", nome, &dia, &mes, &ano);
        idade = calculaIdade(anoAtual, ano);
        printf("%d ", idade);
        if(idade > 18)
            fprintf(saida, "%s: maior de idade\n", nome);
        if(idade == 18)
            fprintf(saida, "%s: entrando na maior idade\n", nome);
        if(idade < 18)
            fprintf(saida, "%s: menor de idade\n", nome);
    }

    fclose(entrada);
    fclose(saida);
}