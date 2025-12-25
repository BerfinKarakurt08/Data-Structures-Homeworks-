#include <stdio.h>
#include <ctype.h>
char stack[100];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if(top == -1)return -1;
    return stack[top--];
}


int precedence(char c) {
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return 0;}

void infixToPostfix(char* exp) {
    int i = 0;
    while(exp[i] != '\0') {
        char c = exp[i];
        
       
        if(isalnum(c)) {
            printf("%c", c);
        }
      
        else if(c == '(') {
            push(c);
        }
       
        else if(c == ')') {
            while(top != -1 && stack[top] != '(')
                printf("%c", pop());
            pop(); 
        }
      
        else {
            while(top != -1 && precedence(stack[top]) >= precedence(c))
                printf("%c", pop());
            push(c);  }
        i++;
    }
    
  
    while(top != -1)
        printf("%c", pop());
    
    printf("\n");
}

int main() {
    char expression[] = "A+B*(C^D-E)";
    printf("Infix: %s\n", expression);
    
    printf("Postfix:");
    infixToPostfix(expression);
    
    return 0;
}
