#include "BTree.h"
#include <stdio.h>
#include <stdlib.h>

ArvB* arvB_cria()
{
    ArvB* nova = (ArvB*) malloc(sizeof(NO));
    (*nova)->ehFolha = TRUE;
    (*nova)->nChaves = 0;

    for(int i = 0; i < ORDEM - 1; i++)
        (*nova)->filhos[i] = NULL;

    return nova;
}

int arvB_insere(ArvB *raiz, int valor)
{
    int i = 0;

    if(!(*raiz))
    {
        raiz = arvB_cria();
        (*raiz)->chaves[0] = valor;

        return TRUE;
    }

    // Caso em que ainda ha espaço no noh para a insercao
    if((*raiz)->nChaves < ORDEM - 1)
    {
        // Determinacao da posicao da chave a ser inserida no noh
        while(valor > (*raiz)->chaves[i])
            i++;

        for(int j = ORDEM - 1; j > i; j--)
            (*raiz)->chaves[j] = (*raiz)->chaves[j - 1];

        (*raiz)->chaves[i] = valor;
        return TRUE;
    }
    else
    {
        int medio = (ORDEM - 1) / 2;
        ArvB* novaRaiz = arvB_cria();
        ArvB* FilhoEsq = arvB_cria();
        ArvB* FilhoDir = arvB_cria();

        (*novaRaiz)->filhos[0] = FilhoEsq;
        (*novaRaiz)->filhos[1] = FilhoDir;

        // Tratamento da parte esquerda do split
        for(int j = 0; j <= medio; j++)
            (*novaRaiz)->filhos[0]->chaves[j] = (*raiz)->chaves[j];

        // Tratamento da parte direita do split
        for(int j = medio + 1; j < ORDEM - 1; j++)
            (*novaRaiz)->filhos[1]->chaves[j] = (*raiz)->chaves[j];
        
        
    }
}

int main()
{
    printf("Trabalho de ORI\n");
    ArvB* p = arvB_cria();

    for(int i = 0; i < ORDEM - 1; i++)
    {
        arvB_insere(p, i);
    }

    for(int i = 0; i < ORDEM - 1; i++)
    {
        printf("%d ", (*p)->chaves[i]);
    }

    free(p);
    return 0;
}