#include <stdio.h>
#include <ctype.h>

char stack[100];
int top=-1;

void push(char c) {
    stack[++top] =c;
}

char pop() {
    if(top==-1) return -1;
    return stack[top--];
}

int precedence(char c) {
    if(c=='+' || c=='-') return 1;
    if(c=='*' || c=='/') return 2;
    return 0;
}

void toPostfix(char*exp) {
    int i =0;
    while(exp[i] != '\0') {
        char k =exp[i];

        if(isalnum(k)) {
            printf("%c", k);
        }
        else if(k=='(') {
            push(k);
        }
        else if(k==')') {
            while(top!= -1 && stack[top] != '(')
                printf("%c", pop());
            pop();
        }
        else {
            while(top!= -1 && precedence(stack[top])>= precedence(k))
                printf("%c", pop());
            push(k);
        }
        i++;
    }

    while(top!= -1)
        printf("%c", pop());
    printf("\n");
}

int main() {
    char ifade[] ="a+b*(c^d-e)";
    toPostfix(ifade);
    return 0;
}
