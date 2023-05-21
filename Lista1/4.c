#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *f;
    char arq[20];
    char c;
    int countC = 0;
    int countV = 0;

    // Leitura do nome do arquivo
    scanf("%s", arq);

    // Abre o arquivo para a leitura. Retorna um erro caso o arquivo não exista
    f = fopen(arq, "r");
    if(f == NULL)
    {
        printf("Arquivo '%s' não encontrado\n", arq);
        return 0;
    }

    // Percorre o arquivo inteiro, identificando as vogais
    while(1)
    {
        c = fgetc(f);
        c = toupper(c);
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            countV++;
        if(c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U' && c != ' ' && c != '\n' && c != '.' && c != ',')
            countC++;

        if(feof(f))
            break;
    }

    // Mensagem para o usuário
    printf("O arquivo '%s' tem %d vogais e %d consoantes\n", arq, countV, countC);

    fclose(f);
}