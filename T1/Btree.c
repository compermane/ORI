#include "BTree.h"
#include <stdio.h>
#include <stdlib.h>

// Cria um ponteiro para um noh de arvore B
ArvB* arvB_cria()
{
    // Aloca um espaco na memoria
    ArvB* nova = (ArvB*) malloc(sizeof(NO));

    // Faz o set de valores iniciais
    (*nova)->nChaves = 0;
    (*nova)->ehFolha = TRUE;

    // Inicialmente, cada filho do novo noh nao possui
    // referencia para seus filhos
    for(int i = 0; i < ORDEM - 1; i++)
        (*nova)->filhos[i] = NULL;

    return nova;
}

// Funcao que deleta uma Arvore B dada a sua raiz
void arvB_destroi(ArvB* raiz)
{
    // Se a raiz estiver nula, retorna
    if(!(*raiz))
        return;

    // Caso contrario, destroi recursivamente cada filho da
    // raiz
    for(int i = 0; i < ORDEM - 1 && (*raiz)->filhos[i] != NULL; i++)
        arvB_destroi((*raiz)->filhos[i]);

    // Aqui, a raiz ja nao possui mais filhos
    free(raiz);
}

// Busca um valor em uma arvore B, retornando 1 (TRUE)
// caso seja encontrado e 0 (FALSE) caso contrario
int arvB_busca(ArvB* raiz, int valor)
{
    // Se o noh buscado form folha, busca em seu vetor de chaves
    if((*raiz)->ehFolha)
    {
        for(int i = 0; i < (*raiz)->nChaves; i++)
            if((*raiz)->chaves[i] == valor)
                return TRUE;

        return FALSE;
    }

    int i = 0;
    while(i < ORDEM - 1 && i < (*raiz)->nChaves)
    {
        if((*raiz)->chaves[i] > valor)
            i++;
        else if((*raiz)->chaves[i] == valor)
            return TRUE;
        else
            break;
    }

    return arvB_busca((*raiz)->filhos[i], valor);
}

// Retorna a quantidade de nohs de uma arvore B, dada
// a referencia para a raiz
int arvB_qtd_nos(ArvB* raiz)
{
    if((*raiz)->ehFolha)
        return 1;

    for(int i = 0; i < ORDEM && (*raiz)->filhos[i] != NULL; i++)
        return 1 + arvB_qtd_nos((*raiz)->filhos[i]);
}

// Retorna a quantidade de chaves inseridas em uma arvore B,
// dada a referencia para a raiz
int arvB_qtd_chaves(ArvB* raiz)
{
    if((*raiz)->ehFolha)
        return (*raiz)->nChaves;

    for(int i = 0; i < ORDEM && (*raiz)->filhos[i] != NULL; i++)
        return (*raiz)->nChaves + arvB_qtd_chaves((*raiz)->filhos[i]);

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
    // Caso em que nao ha mais espaço no noh a ser inserido o elemento
    else
    {
        int medio = (ORDEM - 1) / 2;
        // Passo 1: criacao de uma nova raiz
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

// int main()
// {
//     printf("Trabalho de ORI\n");
//     ArvB* p = arvB_cria();

//     for(int i = 0; i < ORDEM - 1; i++)
//     {
//         arvB_insere(p, i);
//     }

//     for(int i = 0; i < ORDEM - 1; i++)
//     {
//         printf("%d ", (*p)->chaves[i]);
//     }

//     free(p);
//     return 0;
// }