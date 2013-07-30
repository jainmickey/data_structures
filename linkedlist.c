#include <stdio.h>
#include <stdlib.h>

struct node {
    int          data;
    struct node* next;
};

int main(){
    struct node* head = malloc(sizeof(struct node));
    struct node* second = malloc(sizeof(struct node));
    struct node* third = malloc(sizeof(struct node));
    head->next = second;
    head->data = 1;
    second->next = third;
    second->data = 2;
    third->next = NULL;
    third->data = 3;
    struct node* current = head;
    while(current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
    return 1;
}
