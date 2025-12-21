#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void destroy(struct Node* head) {
    if (head == NULL) {
        return;
    }

   destroy(head->next);

    printf("Siliniyor: %d\n", head->data);
    free(head);
}
