#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *entrada;
    char arq[20];
    char c;
    int cInt;
    int nLinhas = 0, nPalavras = 0, nChar = 0, letras[26] = {0};

    printf("Digite o nome do arquivo a ser lido: ");
    scanf("%s", arq);

    entrada = fopen(arq, "r");

    while((c = toupper(getc(entrada))) != EOF)
    {
        if(c == '\n')
            nLinhas++;
        if(c == ' ' || c == '\n')
            nPalavras++;
        else
        {
            letras[c - 'A']++;
            printf("c: %d\n", c - 'A');
            nChar++;
        }
    }
    nPalavras++;
    printf("A quantidade de palavras eh %d\n", nPalavras);
    printf("A quantidade de caracteres eh %d\n", nChar);
    
    for(int i = 65; i < 65 + 26; i++)
        printf("A letra %c aparece %d vezes\n", i, letras[i - 65]);

    fclose(entrada);
}