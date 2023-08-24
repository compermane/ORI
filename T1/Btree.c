#include "BTree.h"
#include <stdio.h>
#include <stdlib.h>

int arvB_insere_nao_cheia(ArvB* raiz, int valor);
void arvB_split(ArvB* pai, int indice, ArvB* filho);

// Cria um ponteiro para um noh de arvore B
ArvB* arvB_cria()
{
    printf("bruh5\n");
    // Aloca um espaco na memoria
    ArvB* nova;
    nova = (ArvB*) malloc(sizeof(NO));

    printf("BRUH6\n");
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
    {
        printf("i: %d\n", i);
        arvB_destroi((*raiz)->filhos[i]);
        printf("BRUH");
    }

    // Aqui, a raiz ja nao possui mais filhos
    free(raiz);
}

// Busca um valor em uma arvore B, retornando 1 (TRUE)
// caso seja encontrado e 0 (FALSE) caso contrario
int arvB_busca(ArvB* raiz, int valor)
{
    // Se o noh buscado for folha, busca em seu vetor de chaves
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

    for(int i = 0; i < ORDEM || (*raiz)->filhos[i] == NULL; i++)
        return 1 + arvB_qtd_nos((*raiz)->filhos[i]);
}

// Retorna a quantidade de chaves inseridas em uma arvore B,
// dada a referencia para a raiz
int arvB_qtd_chaves(ArvB* raiz)
{
    if((*raiz)->ehFolha)
        return (*raiz)->nChaves;

    for(int i = 0; i < ORDEM || (*raiz)->filhos[i] == NULL; i++)
        return (*raiz)->nChaves + arvB_qtd_chaves((*raiz)->filhos[i]);

}

int arvB_insere(ArvB *raiz, int valor) 
{
    int flag;

    // Caso em que a raiz esta cheia
    if((*raiz)->nChaves == ORDEM - 1)
    {
        printf("BRUH4");
        ArvB* novaRaiz = (ArvB*) malloc(sizeof(NO));
        (*novaRaiz)->ehFolha = FALSE;
        (*novaRaiz)->filhos[0] = raiz;

        arvB_split(novaRaiz, 0, raiz);
        flag = arvB_insere_nao_cheia(novaRaiz, valor);
    }
    else
        flag = arvB_insere_nao_cheia(raiz, valor);
    return flag;
}

int arvB_insere_nao_cheia(ArvB* raiz, int valor)
{
    int i = (*raiz)->nChaves - 1;
    // Caso em que o noh eh folha
    if((*raiz)->ehFolha)
    {
        while(i >= 0 && valor < (*raiz)->chaves[i])
        {
            if((*raiz)->chaves[i] == valor)
                return FALSE;

            (*raiz)->chaves[i + 1] = (*raiz)->chaves[i];
            i--;
        }
        (*raiz)->chaves[i] = valor;
        (*raiz)->nChaves++;
    }
    // Caso em que o noh nao eh folha
    else
    {
        printf("BRUH1");
        while(i >= 0 && valor < (*raiz)->chaves[i])
            i--;

        i++;
        ArvB* aux = (*raiz)->filhos[i];

        // Caso em que o noh a ser inserido esta cheio
        if((*aux)->nChaves == ORDEM - 1)
        {
            printf("BRUH2");
            arvB_split(raiz, i, aux);
        }

        if(valor > (*raiz)->chaves[i])
            i++;
        
        arvB_insere_nao_cheia(aux, valor);
    }

    return TRUE;
}

void arvB_split(ArvB* pai, int indice, ArvB* filho)
{
    printf("BRUH");
    ArvB* aux = arvB_cria();
    (*aux)->ehFolha = (*filho)->ehFolha;

    int media = ((ORDEM - 1) / 2);
    (*aux)->nChaves = media;

    // Copiando as chaves do filho da direita
    for(int i = 0; i < media; i++)
        (*aux)->chaves[i] =  (*filho)->chaves[i + media];

    // Copiando os ponteiros do filho se o filho nao
    // eh uma raiz
    if(!(*filho)->ehFolha)
    {
        for(int i = 0; i < media; i++)
            (*aux)->filhos[i] = (*filho)->filhos[i + media];
    }

    (*filho)->nChaves = (*filho)->nChaves - media;

    for(int j = (*pai)->nChaves; j > indice; j--)
        (*pai)->chaves[j + 1] = (*pai)->chaves[j];

    (*pai)->chaves[indice] = (*filho)->chaves[media];
    (*pai)->nChaves++;
}

int main()
{
    ArvB* p = (ArvB*) malloc(sizeof(NO));
    (*p)->ehFolha = TRUE;
    (*p)->nChaves = 0;
    for(int i = 0; i < 10; i++)
        arvB_insere(p, i) ? printf("%d SUCESSO\n", i) : printf("PFVDESUCESSO");

    printf("CONTA NOS: %d\n", arvB_qtd_nos(p));
    printf("CONTA CHAVES: %d\n", arvB_qtd_chaves(p));
    arvB_destroi(p);
    printf("BRUH");
    return 0;
}