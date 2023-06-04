#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char* converteBin(int n)
{
    if(n == 0)
        return "0";
    int rem, i = 0;
    int bits[32];

    while(n > 0)
    {
        bits[i] = n % 2;
        n = n / 2;
        i++;
    }

    char *bin = (char*) malloc((i + 1) * sizeof(char));
    for(int j = i - 1; j >= 0; j--)
        bin[i - 1 - j] = bits[j] + '0';

    bin[i] = '\0';
    return bin;
}

int main()
{
    FILE *saida = fopen("saida_16.txt", "w");

    int v[10] = {10, 46, 378198, 900, 87, 1234, 4, 0, 2, 1};

    for(int i = 0; i < 10; i++)
        fprintf(saida, "%d: %s\n", v[i], converteBin(v[i]));

    fclose(saida);
    return 0;
}