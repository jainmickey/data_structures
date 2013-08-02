#include<stdio.h>
#include<stdlib.h>

typedef struct node* Node;
struct node {
    int  data;
    Node next;
};

void AppendNode(Node* headRef, int num, int pos);
void DeleteNode(Node* headRef, int loc);
void Traverse(Node head);
int ListLength(Node head);

int main()
{
    int i, n, num, pos;
    Node head = NULL;
    while(1) {
        printf("\t\t\tMENU\n");
        printf("\t1. Insert a Node at starting.\n");
        printf("\t2. Insert a Node at specific position.\n");
        printf("\t3. Insert a Node at End.\n");
        printf("\t4. Delete a Node at starting.\n");
        printf("\t5. Delete a Node at specific position.\n");
        printf("\t6. Delete a Node at End.\n");
        printf("\t7. Display the List.\n");
        printf("\t8. Exit.\n");
        printf("Enter your choice:- ");
        scanf("%d", &n);
        switch(n) {
            case 1:
                printf("Enter the value:- ");
                scanf("%d", &num);
                AppendNode(&head, num, 1);
                break;
            case 2:
                printf("Enter the value:- ");
                scanf("%d", &num);
                printf("Enter the position:- ");
                scanf("%d", &pos);
                AppendNode(&head, num, pos);
                break;
            case 3:
                printf("Enter the value:- ");
                scanf("%d", &num);
                AppendNode(&head, num, 0);
                break;
            case 4:
                DeleteNode(&head, 1);
                break;
            case 5:
                printf("Enter the location:- ");
                scanf("%d", &num);
                DeleteNode(&head, num);
                break;
            case 6:
                DeleteNode(&head, 0);
                break;
            case 7:
                printf("The list i):\n");
                Traverse(head);
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("You have entered a wrong choice.\n");
                break;
        }
    }
}

void AppendNode(Node* headRef, int num, int pos) {
    Node current = *headRef;
    Node newNode;

    newNode = malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = NULL;

    if(current == NULL) {
        *headRef = newNode;
    }
    else {
        if(pos == 1) {
            newNode->next = current;
            *headRef = newNode;
        }
        else if(pos == 0) {
            while(current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
        else {
            if(pos>1 && ListLength(current)>=pos) {
                int i;
                for(i=0; i<pos-2; i++) {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
            }
            else {
                printf("You have entered a wrong position.\n");
                return;
            }
        }
    }
    printf("The list after insertion is:- \n");
    Traverse(*headRef);
}

void DeleteNode(Node* headRef, int loc) {
    Node current = *headRef;
    if(current != NULL) {
        if(loc == 0) {
            if(current->next == NULL)
                *headRef = NULL;
            else {
                while(current->next->next != NULL) {
                    current = current->next;
                }
                current->next = NULL;
            }
        }
        else if(loc == 1) {
            *headRef = current->next;
        }
        else {
            if(loc>0 && ListLength(current)>loc) {
                int i;
                for(i=0; i<loc-2; i++)
                    current = current->next;
                current->next = current->next->next;
            }
            else
                printf("You have entered wrong location.\n");
        }
    }
    else
        printf("List is Empty.\n");
    printf("The list after deletion is:-\n");
    Traverse(*headRef);
}

int ListLength(Node head) {
    int count = 0;
    Node current = head;
    while(current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void Traverse(Node head) {
    Node current = head;
    if(current != NULL){
        printf("\n%d", current->data);
        current = current->next;
        while(current != NULL) {
            printf(" -> %d", current->data);
            current = current->next;
        }
        printf("\n");
    }
    else
        printf("List is Empty.\n");
}
