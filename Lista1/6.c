#include <stdio.h>
#include <ctype.h>
#define TAM_ALFABETO 26

int main()
{
    int qtd[TAM_ALFABETO] = {0};
    char arq[20];
    char c;
    FILE *f;

    scanf("%s", arq);
    
    f = fopen(arq, "r");
    if(f == NULL)
    {
        printf("O arquivo '%s' nao existe\n", arq);
        return 0;
    }

    while(1)
    {
        c = fgetc(f);
        c = tolower(c);

        if(isalpha(c))
        {
            int index =  c - 'a';
            qtd[index]++;
        }

        if(feof(f))
            break;
    }

    for(int i = 0; i < TAM_ALFABETO; i++)
        printf("%c: %d\n", 'a' + i, qtd[i]);

    fclose(f);
}