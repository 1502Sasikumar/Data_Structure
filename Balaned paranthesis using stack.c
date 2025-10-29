//Balaned paranthesis using stack
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

# define MAX 100

char stack[MAX];  //stack implementation
int top=-1;

void push(char c)
{
    if(top == MAX-1){
        printf("Stack Overflow.\n");
        exit(0);
    }
    else
        stack[++top]=c;
}

char pop()
{
    if(top == -1){
        return '\0';
    }
    else
       return stack[top--];
    
}

int isBalanced(char *exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            char topChar = pop();
            if (topChar == '\0') {
                return 0; 
            }
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return 0; 
            }
        }
    }
    return top == -1; 
}

int main()
{
    char exp[MAX];
    printf("Enter the Expression :");
    scanf("%s",exp);
    
    if(isBalanced(exp)){
        printf("Balanced.\n");
    }
    else
    {
        printf("Unbalanced.\n");
    }
    return 0;
}
