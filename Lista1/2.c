#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE *f;
    char arq[10];
    char c;
    int n = 0;

    // Lê o nome do arquivo
    scanf("%s", arq);

    // Abre o arquivo para leitura
    f = fopen(arq, "r");

    // Lê todos os caracteres do arquivo
    while(1)
    {
        c = fgetc(f);
        if(c == '\n')
            n++;
        if(feof(f))
            break;
    }

    // Adiciona a última linha ao contador de linhas do arquivo
    n++;

    // Mensagem para o usuário
    printf("O arquivo %s tem %d linhas", arq, n);

    fclose(f);
}