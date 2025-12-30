#include <stdio.h>

int tree[100];

void setRoot(int key) {
    tree[0] = key;
}
void setLeft(int key, int parentIndex) {
    if(tree[parentIndex] == -1) {
     return;
     }
    tree[(parentIndex * 2) + 1] = key;
}

void setRight(int key, int parentIndex) {
    if(tree[parentIndex] == -1) {
        return;
    }
    tree[(parentIndex * 2) + 2] = key;
 }

void printTree() {
    for(int i = 0; i < 10; i++) {
        if(tree[i] != -1)
         printf("Index %d: %d\n", i, tree[i]);
        else
          printf("Index %d: -\n", i);
       }
   }

int main() {
    for(int i = 0; i < 100; i++) tree[i] = -1;

    setRoot(10);
    setLeft(20, 0);
    setRight(30, 0);
    setLeft(40, 1);
    setRight(50, 1);
    setLeft(60, 2);
    printTree();

return 0;
}
