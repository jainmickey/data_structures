#include<stdio.h>
#include<stdlib.h>

typedef struct node* Node;
struct node {
    int  data;
    Node next;
};

Node AppendNode(Node* headRef, int num);

int main()
{
    int i;
    Node head = NULL;
    for(i=0; i<5; i++)
    {
        AppendNode(&head, i);
    }
    Node current = head;
    while(current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
    return 1;
}

Node AppendNode(Node* headRef, int num)
{
    Node current = *headRef;
    Node newNode;

    newNode = malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = NULL;

    if(current == NULL)
    {
        *headRef = newNode;
    }
    else {
        while(current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
    }
}
