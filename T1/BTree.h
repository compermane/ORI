#ifndef BTREE_H
#define BTREE_H

#define ORDEM 8
#define FALSE 0
#define TRUE 1

typedef struct NO* ArvB;

struct NO
{
    int chaves[ORDEM - 1];
    ArvB* filhos[ORDEM];
    int nChaves;
    int ehFolha;
} NO;

ArvB* arvB_cria();
void arvB_destroi(ArvB *raiz);
int arvB_insere(ArvB* raiz, int valor);
int arvB_remove(ArvB *raiz, int valor);
int arvB_busca(ArvB *raiz, int valor);
int arvB_qtd_nos(ArvB *raiz);
int arvB_qtd_chaves(ArvB *raiz);

#endif