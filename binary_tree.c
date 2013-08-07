#include<stdio.h>
#include<stdlib.h>

typedef struct node* Node;
struct node {
    int data;
    Node left;
    Node right;
};

Node NewNode(int data);
Node insert(Node node, int data);
void printTree(Node node);
int size(Node node);
int maxDepth(Node node);
int minValue(Node node);
void printPostOrder(Node node);

int main()
{
    int i, n;
    Node root = NULL;
    printf("Enter the values in Tree:- ");
    for(i=0; i<3; i++) {
        scanf("%d", &n);
        root = insert(root, n);
    }
    printTree(root);
    printf("\n");
    printf("Size of Tree is:- %d\n",size(root));
    printf("Max Depth of Tree is:- %d\n",maxDepth(root));
    printf("Min Value of Tree is:- %d\n",minValue(root));
    printf("The Post Order is:- ");
    printPostOrder(root);
    printf("\n");
}

Node newNode(int data) {
    Node node = malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

Node insert(Node node, int data) {
    if (node == NULL)
        return(newNode(data));
    else {
        if (data <= node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);

        return (node);
    }
}

void printTree(Node node) {
    if (node == NULL)
        return;

    printTree(node->left);
    printf("%d ", node->data);
    printTree(node->right);
}

int size(Node node) {
    if(node == NULL)
        return (0);
    else
        return (size(node->left) + 1 + size(node->right));
}

int maxDepth(Node node) {
    if (node == NULL)
        return (0);
    else {
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);

        if(leftDepth > rightDepth)
            return (leftDepth+1);
        else
            return (rightDepth+1);
    }
}

int minValue(Node node) {
    Node current = node;
    while(current->left != NULL)
        current = current->left;
    return (current->data);
}

void printPostOrder(Node node) {
    if(node == NULL)
        return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("%d ", node->data);
}
