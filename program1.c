//number of nodes in a binary tree


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}node;
node* newNode(int data)
{
  node * Node = (node *)malloc(sizeof(node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}

int left_height(node* node)
{
    int ht = 0;
    while (node) {
        ht++;
        node = node->left;
    }
    return ht;
}

int right_height(node* node)
{
    int ht = 0;
    while (node) {
        ht++;
        node = node->right;
    }


    return ht;
}

int TotalNodes(node* root)
{
    if (root == NULL)
        return 0;
    int lh = left_height(root);
    int rh = right_height(root);

    if (lh == rh)
        return (1 << lh) - 1;

    return 1 + TotalNodes(root->left) + TotalNodes(root->right);
}

int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(9);
    root->right->right = newNode(8);
    root->left->left->left = newNode(6);
    root->left->left->right = newNode(7);
    printf("%d",TotalNodes(root));
    return 0;
}
