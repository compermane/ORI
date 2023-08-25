#include "BTree.h"
#include <stdio.h>

/*
Nomes:
    - Eugenio Akinori Kisi Nishimiya RA: 811598
    - Gabriel de Souza Cavalca Leite RA: 813615
    - Nataly Cristina da Silva RA: 812719
*/

int main()
{
    // Cria uma arvore B
    ArvB* raiz = arvB_cria();
    int aux, naoAchadas = 0, achadas = 0;

    aux = arvB_insere(raiz, 5);
    // Insercao de 10 chaves, 1 repetida
    for(int i = 0; i < 10; i++)
    {
        aux = arvB_insere(raiz, i);
        (aux) ? printf("Insercao da chave %d: Bem sucedida\n", i) : printf("Insercao da chave %d: Mal sucedida (a chave ja existe)\n", i);
    }

    // Teste das contagens
    printf("Quantidade de nohs: %d\n", arvB_qtd_nos(raiz));          
    printf("Quantidade de chaves: %d\n", arvB_qtd_chaves(raiz));   

    // Faz a busca por chaves
    for(int i = 0; i < 20; i++)
    {
        aux = arvB_busca(raiz, i);
        printf("Buscando pela chave %d: %s", i, (aux) ? "Achou\n" : "Nao achou\n");
    }

    // Testa a funcao arvB_destroi
    arvB_destroi(raiz);
    printf("Fim do programa.\n");

    return 0;
}