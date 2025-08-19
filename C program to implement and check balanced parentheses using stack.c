//C program to implement and check balanced parentheses using stack
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define MAX 100

char stack[MAX];
int top=-1;

void push(char c)
{
    if(top == MAX-1)
        printf("Stack Overflow.\n");
    else
        stack[top++]=c;
}

char pop()
{
    if(top == -1)
        return '\0';
    else
        return stack[top--];
}

int isBalanced(char *exp)
{
    for(int i=0;exp[i]!=0;i++){
        char c = exp[i];
        if(c == '(' || c == '{' || c == '['){
            push(c);}
        else if(c == ')' || c == '}' || c == ']'){
            char topch = pop();
            if(topch == '\0')
                return '\0';
        if (( c == ')' && topch != '(' ) ||
    ( c == '}' && topch != '{' ) ||
    ( c == ']' && topch != '[' ))
    return 0;

        }
    }
    return top == -1;
    
}
int main()
{
    char ch[MAX];
    printf("Enter the Expression: ");
    scanf("%s",ch);
    if(isBalanced(ch))
        printf("Balanced.\n");
    else 
        printf("Unbalanced.\n");
    return 0;
}
