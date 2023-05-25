#include <stdio.h>
#include <ctype.h>

int main()
{
    // Declaração de variáveis
    FILE *entrada, *saida;      // Arquivos a serem lidos/escritos
    char arq[20];               // Nome do arquivo a ser lido (input do usuario)
    char c;                     // Caracter do arquivo a ser lida

    // Entrada de dados
    printf("Digite o arquivo a ser lido: ");
    scanf("%s", arq);

    // Abre o arquivo indicado. Retorna uma mensagem, caso o arquivo não exista
    entrada = fopen(arq, "r");
    if(entrada == NULL)
    {
        printf("Arquivo nao encontrado!");
        return 1;
    }
    saida = fopen("upper.txt", "w");

    // Percorre todo o arquivo de entrada, convertendo seus caracters para uppercase
    while((c = fgetc(entrada)) != EOF)
        fputc(toupper(c), saida);

    // Fecha os arquivos
    fclose(entrada);
    fclose(saida);

    return 0;
}