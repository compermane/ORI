#include <stdio.h>
#include <string.h>

#define LINE_MAX_LENGHT 100
#define NAME_MAX_LENGHT 40

int main()
{
    FILE *entrada = fopen("notas.txt", "r");
    double nota, maiorNota = 0;;
    char nome[NAME_MAX_LENGHT], nomeMaiorNota[NAME_MAX_LENGHT], str[10];

    while(fscanf(entrada, "%s %s %lf", nome, str, &nota) != EOF)
    {
        if(nota > maiorNota)
        {
            strcpy(nomeMaiorNota, nome);
            maiorNota = nota;
        }
    }

    printf("O aluno %s recebeu a maior nota %.2lf", nomeMaiorNota, maiorNota);
    fclose(entrada);
}