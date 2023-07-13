#include <stdio.h>
#include <stdlib.h>

typedef struct no Node;

struct no
{
    Node* left;
    Node* right;
    int value;
};

Node* novoNo(int data)
{
    Node* temp = malloc(sizeof(Node));
    temp->value = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* insere(Node* node, int data)
{
    if(node == NULL)
        return novoNo(data);

    if(data < node->value)
        node->left = insere(node->left, data);

    else if(data >= node->value)
        node->right = insere(node->right, data);

    return node;
}

int contaNosNaoFolha(Node* raiz, int count)
{
    if(raiz == NULL)
        return count;

    if(raiz->left != NULL || raiz->right != NULL)
        count++;

    count = contaNosNaoFolha(raiz->left, count);
    count = contaNosNaoFolha(raiz->right, count);
}

int main()
{
    Node* root = NULL;
    root = insere(root, 50);
    insere(root, 30);
    insere(root, 20);
    insere(root, 40);
    insere(root, 70);
    insere(root, 60);
    insere(root, 80);

    printf("Quantidade de nos nao folha: %d\n", contaNosNaoFolha(root, 0));

    return 0;
}