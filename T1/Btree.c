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
    {
        return;
    }
    // Caso contrario, destroi recursivamente cada filho da
    // raiz
    for(int i = 0; i < ORDEM - 1 && (*raiz)->filhos[i] != NULL; i++)
    {
        arvB_destroi((*raiz)->filhos[i]);
    }

    // Aqui, a raiz ja nao possui mais filhos
    raiz = NULL;
    free(raiz);

    printf("BRUH");
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

int arvB_insere(ArvB *raiz, int valor) {
  int i = 0;
  int t;

  if (!(*raiz)) // se nao for raiz, cria uma nova
  {
    raiz = arvB_cria();
    (*raiz)->chaves[0] = valor;
    (*raiz)->nChaves = (*raiz)->nChaves + 1;

    return TRUE;
  } else // se a raiz ja existe:
  {
    if ((*raiz)->ehFolha == FALSE) // só insere folha
    {
      i = 0;
      while (valor < (*raiz)->chaves[i] &&
             i < ORDEM - 1) // acha a pos a ser inserida
      {
        if (valor == (*raiz)->chaves[i]) {
          return FALSE;
        }
        i++;
      }
      arvB_insere(((*raiz)->filhos[i]), valor);
    } else {
      if ((*raiz)->nChaves < ORDEM - 1) // sem overflow
      {

        for(int j = ORDEM - 2; j > i; j--)
        {
            (*raiz)->chaves[j] = (*raiz)->chaves[j-1];
        }

        (*raiz)->chaves[i] = valor;
        (*raiz)->nChaves = (*raiz)->nChaves + 1;

        return TRUE;
      }
    }
  }
}


int main()
{
    printf("Trabalho de ORI\n");
    ArvB* p = arvB_cria();
    ArvB* q = arvB_cria();

    for(int i = 0; i < ORDEM - 1; i++)
    {
        arvB_insere(q, i);
    }

    for(int i = 0; i < ORDEM - 1; i++)
        arvB_insere(p, i + 7);

    (*p)->filhos[0] = q;

    for(int i = 0; i < ORDEM - 1; i++)
    {
        printf("%d ", (*p)->chaves[i]);
    }

    printf("\n");

    for(int i = 0; i < ORDEM - 1; i++)
    {
        printf("%d ", (*q)->chaves[i]);
    }

    printf("QTD CHAVES: %d\n", arvB_qtd_chaves(p));
    printf("QTD NOHS: %d", arvB_qtd_nos(p));

    (arvB_busca(p, 90)) ? printf("ACHADO\n") : printf("NAO ACHADO\n");
    (arvB_busca(p, 3)) ? printf("ACHADO\n") : printf("NAO ACHADO\n");
    arvB_destroi(p);
    return 0;
}