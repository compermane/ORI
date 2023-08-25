#include "BTree.h"
#include <stdio.h>
#include <stdlib.h>

// Funcoes auxiliares
ArvB arvB_cria_node();
void arvB_insere_nao_cheia(ArvB raiz, int valor);
void arvB_split(ArvB pai, int indice);

// Cria um node de BTree
ArvB arvB_cria_node()
{
    ArvB nova = (ArvB) malloc(sizeof(struct NO));

    if(nova == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(EXIT_FAILURE);
    }

    nova->nChaves = 0;
    nova->ehFolha = TRUE;

    for(int i = 0; i < ORDEM; i++)
        nova->filhos[i] = NULL;

    return nova;
}

// Cria um ponteiro para uma arvore B
ArvB* arvB_cria()
{
    ArvB* nova = (ArvB*) malloc(sizeof(ArvB));

    if(nova == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(EXIT_FAILURE);
    }

    // Designa um noh para a raiz
    ArvB novoNode = arvB_cria_node();
    *nova = novoNode;

    return nova;
}

// Funcao que deleta uma Arvore B dada a sua raiz
void arvB_destroi(ArvB* raiz)
{
    // Se a raiz já estiver vazia, retorna
    if(*raiz == NULL)
        return;
    
    // Caso contrario, destroi recursivamente cada filho
    for(int i = 0; i <= (*raiz)->nChaves; i++)
        arvB_destroi(&(*raiz)->filhos[i]);

    // Aqui, a raiz ja nao possui mais filhos
    free(*raiz);
    *raiz = NULL;
}

// Retorna a quantidade de chaves inseridas em uma arvore B,
// dada a referencia para a raiz
int arvB_qtd_chaves(ArvB* raiz)
{
    // Caso em que a raiz nao existe
    if(!(*raiz))
        return 0;

    // Se o noh da raiz for folha, retorna sua quantidade de chaves
    if((*raiz)->ehFolha)
        return (*raiz)->nChaves;

    int aux = 0;
    ArvB* auxB = arvB_cria();

    // Enquanto o noh analisado tiver filhos, chama recursivamente a função
    for(int i = 0; i <= (*raiz)->nChaves; i++)
    {
        *auxB = (*raiz)->filhos[i];
        aux = aux + arvB_qtd_chaves(auxB);
    }

    return aux + (*raiz)->nChaves;
}

// Retorna a quantidade de nohs de uma arvore B, dada
// a referencia para a raiz
int arvB_qtd_nos(ArvB* raiz)
{
    // Caso em que a arvore nao existe
    if((*raiz) == NULL)
        return 0;

    // Caso em que o noh da raiz eh folha: ha apenas 1 noh
    if((*raiz)->ehFolha)
        return 1;

    // Caso contrario, percorre todos os seus filhos
    int aux = 0;
    ArvB* auxB = arvB_cria();

    for(int i = 0; i <= (*raiz)->nChaves; i++)
    {
        *auxB = (*raiz)->filhos[i];
        aux = aux + arvB_qtd_nos(auxB);
    }
       
    return (1 + aux);
}

// Busca um valor em uma arvore B, retornando 1 (TRUE)
// caso seja encontrado e 0 (FALSE) caso contrario
int arvB_busca(ArvB* raiz, int valor)
{
    // Se o noh raiz for vazio, retorna FALSE
    if((*raiz) == NULL)
        return FALSE;

    // Encontra a posicao do filho onde a chave esta localizada
    int i = 0;
    while(i < (*raiz)->nChaves && valor > (*raiz)->chaves[i])
        i++;

    // Se o valor buscado for igual a valor armazenado na posicao i,
    // retorna TRUE
    if(valor == (*raiz)->chaves[i])
        return TRUE;

    // Se o node analisado for folha, entao nao ha mais como descer. Nesse
    // caso, a chave buscada nao existe ou esta nesse noh.
    if((*raiz)->ehFolha)
    {
        for(int j = 0; j < (*raiz)->nChaves; j++)
        {
            if(valor == (*raiz)->chaves[j])
                return TRUE;
        }
        return FALSE;
    }

    // Chama recursivamente a busca, explorando os filhos
    ArvB* aux = arvB_cria();
    *aux = (*raiz)->filhos[i];

    return arvB_busca(aux, valor);
}

// Insere um valor dado o ponteiro para a raiz de uma arvore B.
// Retorna TRUE (1) caso a operacao tenha sucesso e FALSE (0)
// caso contrario.
int arvB_insere(ArvB *raiz, int valor) 
{
    // Caso em que a chave a ser inserida ja esta na arvore
    if(arvB_busca(raiz, valor))
        return FALSE;

    // Caso em que a raiz esta cheia
    if((*raiz)->nChaves == ORDEM - 1)
    {
        ArvB* novaRaiz = arvB_cria();
        (*novaRaiz)->ehFolha = FALSE;
        (*novaRaiz)->filhos[0] = *raiz;

        // Eh feito o split do noh
        arvB_split(*novaRaiz, 0);
        *raiz = *novaRaiz;
        // E a chave a ser inserida eh inserida na nova raiz
        arvB_insere_nao_cheia(*novaRaiz, valor);
    }
    // Caso em que a raiz nao esta cheia
    else
        arvB_insere_nao_cheia(*raiz, valor);

    // Retorna a flag
    return TRUE;
}

// Funcao auxiliar para a insercao de chaves em nohs nao cheios
void arvB_insere_nao_cheia(ArvB raiz, int valor)
{
    int i = raiz->nChaves - 1;

    // Caso em que o noh eh folha
    if(raiz->ehFolha)
    {
        while(i >= 0 && valor < raiz->chaves[i])
        {
            raiz->chaves[i + 1] = raiz->chaves[i];
            i--;
        }
        raiz->chaves[i + 1] = valor;
        raiz->nChaves++;
    }
    // Caso em que o noh nao eh folha
    else
    {
        while(i >= 0 && valor < raiz->chaves[i])
            i--;

        i++;

        // Caso em que o noh a ser inserido esta cheio
        if(raiz->filhos[i]->nChaves == ORDEM - 1)
        {
            arvB_split(raiz, i);

            if(valor > raiz->chaves[i])
                i++;
        }
        
        // Executa a funcao recursivamente, ate encontrar um noh nao cheio
        arvB_insere_nao_cheia(raiz->filhos[i], valor);
    }
}

// Particiona um noh, dado o noh pai, e o indice do no filho
void arvB_split(ArvB pai, int indice)
{
    // Media onde havera o particionamento
    int media = (ORDEM / 2) - 1;

    // Determinacao do filho
    ArvB filho = pai->filhos[indice];
    ArvB* novoFilho = arvB_cria();

    (*novoFilho)->ehFolha = filho->ehFolha;
    (*novoFilho)->nChaves = media;

    // Copia a metade direita do filho para o novo filho
    for(int i = 0; i < media; i++)
        (*novoFilho)->chaves[i] = filho->chaves[i + ORDEM / 2];

    // Copiando os ponteiros de filhos, caso o filho 
    // nao seja um noh folha
    if(!(filho->ehFolha))
    {
        for(int i = 0; i < ORDEM / 2; i++)
            (*novoFilho)->filhos[i] = filho->filhos[i + ORDEM / 2];
    }

    // Agora, o filho possui uma quantidade de chaves igual a media
    filho->nChaves = media;

    // Deslocamento para a direita dos filhos do noh pai
    for(int i = pai->nChaves; i >= indice + 1; i--)
        pai->filhos[i + 1] = pai->filhos[i];

    // Insercao do filho na posicao correta
    pai->filhos[indice + 1] = *novoFilho;

    // Promocao de chave
    for(int i = pai->nChaves - 1; i >= indice; i--)
        pai->chaves[i + 1] = pai->chaves[i];

    pai->chaves[indice] = filho->chaves[media];
    pai->nChaves++;
}
