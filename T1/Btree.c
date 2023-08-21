#include "BTree.h"

ArvB* ArvB_cria()
{
    ArvB* nova = (ArvB*) malloc(sizeof(NO));
    return nova;
}

void arvB_destroi(ArvB *raiz)
{
    free(raiz);
}