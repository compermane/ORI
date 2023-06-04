#include <stdio.h>
#include <time.h>
#include <string.h>

#define LINE_MAX_LENGHT 100
#define NAME_MAX_LENGHT 20

int calculaIdade(int dia, int mes, int ano)
{
    printf("aqui");
    time_t atual = time(NULL);
    struct tm *localTime = localtime(&atual);

    int diaAtual = localTime->tm_mday;
    int mesAtual = localTime->tm_mon + 1;
    int anoAtual = localTime->tm_year + 1900;

    int idade = anoAtual - ano;
    if(mes > mesAtual || (mes < mesAtual && dia > diaAtual))
        idade--;
    return idade;
}

int main()
{
    FILE *saida = fopen("idades.txt", "w");
    FILE *entrada = fopen("datas.txt", "r");
    int dia, mes, ano, idade;
    char nome[NAME_MAX_LENGHT], linha[LINE_MAX_LENGHT];

    if(entrada == NULL)
    {
        printf("Arquivo nao encontrado!");
        return 1;
    }

    printf("aqui2");

    while(fgets(linha, LINE_MAX_LENGHT, entrada) != NULL)
    {
        if(linha[strlen(linha) -1] == '\n')
            linha[strlen(linha) - 1] = '\0';
        
        sscanf(linha, "%s %d %d %d", nome, &dia, &mes, &ano);
        idade = calculaIdade(dia, mes, ano);
        fprintf(saida, "%s: %d\n", nome, idade);
    }
    printf("BRUH");
    fclose(saida);
    fclose(entrada);
}