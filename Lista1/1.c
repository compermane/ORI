#include <stdlib.h>
#include <stdio.h>

int main()
{
    // Declaração de arquivo de escrita de dados
    FILE *f = fopen("arq.txt", "w");
    char letra;
    while(1)
    {
        // Leitura de caracter
        scanf("%c", &letra);

        // Para a leitura de caracteres caso entre com '0'
        if(letra == '0')
            break;

        // Ignora a entrada de enter do usuário
        if(letra == '\n')
            continue;

        // Coloca o caracter no arquivo
        fputc(letra, f);
    }

    fclose(f);
}