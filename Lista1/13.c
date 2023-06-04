#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGHT 20

int main()
{
    FILE *saida = fopen("telefones.txt", "w");
    int numero;
    char nome[MAX_LENGHT];

    while(1)
    {
        printf("Digite o nome da pessoa: ");
        scanf("%s", nome);

        printf("Digite o numero da pessoa (0 para parar): ");
        scanf("%d", &numero);

        if(numero == 0)
            break;

        fprintf(saida, "%s %d\n", nome, numero);
    }

    fclose(saida);
}