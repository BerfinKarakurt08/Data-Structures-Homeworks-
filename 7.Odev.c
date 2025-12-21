#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[10];
    struct Node *left,*right;
};

struct Node* createNode(char* val) {
    struct Node* node =(struct Node*)malloc(sizeof(struct Node));
    strcpy(node->data,val);
    node->left=NULL;
    node->right=NULL;
    return node;
}

void printTree(struct Node* root, int space) {
    if (root ==NULL) return;
    
    space +=5;
    printTree(root->right,space);
    
    printf("\n");
    for (int i=5; i < space; i++) printf(" ");
    printf("%s\n",root->data);
    
    printTree(root->left, space);
}

int main() {
    struct Node*root=createNode("+");
    root->left=createNode("-");
    root->right=createNode("*");
    
    root->left->left=createNode("a");
    root->left->right=createNode("b");
    
    root->right->left=createNode("c");
    root->right->right=createNode("2");

    printTree(root,0);
    return 0;
}