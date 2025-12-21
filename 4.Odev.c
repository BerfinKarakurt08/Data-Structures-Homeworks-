#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!=NULL) {
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void printRecursive(struct Node* head) {
    if (head == NULL) {
        return;
    }
    printf("%d ",head->data);
    printRecursive(head->next);
}
