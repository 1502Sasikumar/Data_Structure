// Program to store and restorenusing stack
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack_arr[MAX];
int top=-1;
void push(int data){
    if(top==MAX-1){
        printf("stack is overflow");
        return;
    }
    top=top+1;
    stack_arr[top]=data;
    printf("Stored:%d\n",data);
}
int pop(){
    if(top==-1){
        printf("stack is underflow");
        exit(1);
    }
    int value;
    value=stack_arr[top];
    top=top-1;
    printf("Restored:%d\n",value);
    return value;
}
void display(){
    int i;
    if(top==-1){
        printf("stack is empty");
    }
    for(i=0;i<=top;i++){
        printf("%d ",stack_arr[i]);
    }
    printf("\n");
}
int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();
    pop(50);
    pop(40);
    display();
}
