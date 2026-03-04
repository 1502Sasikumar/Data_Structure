// Stack Implementation using Array (DS)
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct stack{
    int arr[MAX];
    int top;
};

void init(struct stack *s){
     s->top = -1;
}

void push(struct stack *s,int value){
    
    if(s->top == MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top]=value;
}

int pop(struct stack *s){
    
    if(s->top == -1){
        printf("Stack underflow\n");
        return -1;
    }
    int value = s->arr[s->top];
    s->top--;
    
    return value;
}

int peek(struct stack *s){
    
    if(s->top == -1){
        printf("Stack is Empty\n");
        return -1;
    }
    return s->arr[s->top];
    
}
void display(struct stack *s)
{
    for(int i=0; i<=s->top; i++){
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}
int main()
{
    struct stack s;

    init(&s);

    push(&s,10);
    push(&s,20);
    push(&s,30);
    push(&s,40);
    display(&s);

    printf("Top element: %d\n", peek(&s));
    printf("Popped element: %d\n", pop(&s));
    printf("New Top: %d\n", peek(&s));

    return 0;
}
