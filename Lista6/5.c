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

int calculaAltura(Node* node)
{
    if(node == NULL)
        return 0;

    int alturaEsquerda = calculaAltura(node->left);
    int alturaDireita = calculaAltura(node->right);

    if(alturaEsquerda >= alturaDireita)
        return alturaEsquerda + 1;

    return alturaDireita + 1;

}

int main()
{
    Node* root = NULL;
    root = insere(root, 8);
    insere(root, 3);
    insere(root, 10);
    insere(root, 1);
    insere(root, 6);
    insere(root, 4);
    insere(root, 7);
    insere(root, 14);
    insere(root, 13);

    printf("Altura da arvore eh: %d\n", calculaAltura(root));

    return 0;
}