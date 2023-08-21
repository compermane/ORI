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

Node* deleta(Node* node, int data)
{
    // Base da recurcao
    if(node == NULL)
        return node;

    if(data < node->value)
    {
        node->left = deleta(node->left, data);
        return node;
    }
    else if(data > node->value)
    {
        node->right = deleta(node->right, data);
        return node;
    }

    // A partir daqui, node->value == data
    // Caso em que o no a ser removido tem pelo menos 1 filho
    if(node->left == NULL)
    {
        Node* temp = (Node*) malloc(sizeof(Node));
        temp = node->right;

        free(node);
        return temp;
    }

    else if(node->right == NULL)
    {
        Node* temp = (Node*) malloc(sizeof(Node));
        temp = node->left;

        free(node);
        return temp;
    }

    // Caso em que ambos os filhos existem
    else
    {
        Node* succParent = (Node*) malloc(sizeof(Node));
        succParent = node;

        Node* succ = (Node*) malloc(sizeof(Node));
        succ = node->right;

        while(succ != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }

        if(succParent != node)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        node->value = succ->value;

        free(succ);
        return node;
    }

}

Node* deletaImpares(Node* node)
{
    printf("BRUH3\n");
    if(node == NULL)
        return node;

    node = deletaImpares(node->left);
    printf("BRUH5000\n");
    if((node->value % 2) != 0)
    {
        printf("AI QUE SAUDADE\n");
        node = deleta(node, node->value);
        return node;
    }

    printf("BRUH1\n");

    node = deletaImpares(node->right);
    if((node->value % 2) != 0)
    {
        node = deleta(node, node->value);
        return node;
    }

    printf("BRUH2\n");

    return node;

}

void preorder(Node* node)
{
    if(node == NULL)
        return;

    printf("%d ", node->value);

    preorder(node->left);
    preorder(node->right);

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

    printf("A arvore eh: ");
    preorder(root);

    printf("\nDeletando impares: ");
    root = deletaImpares(root);

    printf("A arvore agora eh: ");
    preorder(root);

    return 0;

}