#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertEnd(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head_ref;
     new_node->data = data;
    new_node->next = *head_ref;

    
    if (*head_ref == NULL) {
        new_node->next = new_node; 
        *head_ref = new_node;
    } 
    else {
         while (temp->next != *head_ref) {
            temp = temp->next;
        }
        temp->next = new_node; 
    }
}

void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;

    struct Node *curr = *head, *prev;

     if (curr->data == key && curr->next == curr) {
        *head = NULL;
        free(curr);
         return;
    }

    if (curr->data == key) {
        prev = *head;
       
        while (prev->next != *head)
            prev = prev->next;
            
        prev->next = curr->next;
        *head = curr->next;
        free(curr);
    }
   
    else {
        while (curr->data != key) {
            if (curr->next == *head) {
                printf("Eleman bulunamadi.\n");
             return;
            }
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        free(curr);
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("(Head)\n");
    }
}

int main() {
    struct Node* head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("Circular List: ");
    printList(head);

    printf("20 Silindi: ");
    deleteNode(&head, 20); 
    printList(head);
    
    printf("10 (Head) Silindi: ");
    deleteNode(&head, 10); 
    printList(head);
  return 0;
}

