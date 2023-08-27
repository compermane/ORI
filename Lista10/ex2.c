#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX_LENGHT 20

char* getNome(char fileName[], int index)
{
    FILE* f = fopen(fileName, "r");
    char* nome = (char*) malloc(NAME_MAX_LENGHT * sizeof(char));
    char line[NAME_MAX_LENGHT];

    int i = 0;
    while(i <= index)
    {
        if(feof(f))
            return NULL;

        fgets(nome, NAME_MAX_LENGHT, f);
        i++;
    }
    fclose(f);
    return nome;
}

void match(char fileNameA[], char fileNameB[])
{
    FILE* A = fopen(fileNameA, "r");
    FILE* B = fopen(fileNameB, "r");
    FILE* res = fopen("result.txt", "w");

    char* nomeA = (char*) malloc(NAME_MAX_LENGHT * sizeof(char));
    char* nomeB = (char*) malloc(NAME_MAX_LENGHT * sizeof(char));
    int a = 0, b = 0;

    nomeA = getNome(fileNameA, a);
    nomeB = getNome(fileNameB, b);

    while(nomeA != NULL && nomeB != NULL)
    {
        if(strcmp(nomeA, nomeB) < 0)
        {
            a++;
            nomeA = getNome(fileNameA, a);
        }
        else if(strcmp(nomeA, nomeB) > 0)
        {
            b++;
            nomeB = getNome(fileNameB, b);
        }
        else
        {
            fprintf(res, "%s", nomeA);
            a++;
            b++;
            nomeA = getNome(fileNameA, a);
            nomeB = getNome(fileNameB, b);
        }
    }

    free(nomeA);
    free(nomeB);

    fclose(A);
    fclose(B);
    fclose(res);

    return;
}

int main()
{
    match("nomesA.txt", "nomesB.txt");
    return 0;
}