#include <ctype.h>
#include <stdio.h>

int main()
{
    FILE *f;
    char arq[20];
    char c, aux;
    int count = 0;

    printf("Digite o arquivo que se deseja procurar: ");
    scanf("%s", arq);

    printf("Digite a letra que se deseja contar: ");
    scanf("%*c%c", &c);

    c = toupper(c);

    f = fopen(arq, "r");
    if(f == NULL)
    {
        printf("O arquivo '%s' nao existe\n", arq);
        return 0;
    }

    while(1)
    {
        aux = fgetc(f);
        aux = toupper(aux);

        if(aux == c)
            count++;

        if(feof(f))
            break;
    }

    printf("A letra '%c' aparece %d vezes no arquivo '%s'\n", c, count, arq);

    fclose(f);
}