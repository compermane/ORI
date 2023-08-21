#ifndef BTREE_H
#define BTREE_H

#include <stdio.h>
#include <stdlib.h>

#define ORDEM 8

typedef struct NO* ArvB;

struct NO 
{
    int qtd;
    int chaves[ORDEM - 1];
    ArvB filhos[ORDEM];
}

ArvB* arvB_cria();
void arvB_destroi(ArvB *raiz);
int arvB_insere(ArvB* raiz, int valor);
int arvB_remove(ArvB *raiz, int valor);
int arvB_busca(ArvB *raiz, int valor);
int arvB_qtd_nos(ArvB *raiz);
int arvB_qtd_chaves(ArvB *raiz);

NO* criaNo(int chave);


#endif