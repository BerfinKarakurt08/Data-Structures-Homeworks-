#include <stdio.h>

char tree[20];

void init() {
    for(int i=0;i<20;i++) tree[i] ='-';
}

void setRoot(char k) {
    tree[0] = k;
}

void setLeft(char k,int parent) {
    if(tree[parent]=='-') return;
    tree[(parent*2) +1] =k;
}

void setRight(char k,int parent) {
    if(tree[parent]=='-') return;
    tree[(parent*2) +2] =k;
}

int main() {
    init();
    setRoot('A');
    setLeft('B',0);
    setRight('C',0);

    for(int i=0; i<10; i++) {
        if(tree[i] != '-')
            printf("Index %d:%c\n",i,tree[i]);
    }
    return 0;
}
