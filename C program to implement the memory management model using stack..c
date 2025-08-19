//C program to implement the memory management model using stack.
#include<stdio.h>
#include<stdlib.h>
# define MAX 100

int stack[MAX];
int top = -1;

void allocateMemory(int blockid)
{
    if(top == MAX-1){
        printf("Stack Overflow Memory full no more can be allocated.\n");
    }
    else
    {
        stack[top++] = blockid;
        printf("Allocated Memory block %d\n",blockid);
    }
}

void deallocateMemory()
{
    if(top == -1){
        printf("Stack is Empty Memory cannot be allocated.\n");
        return;
    }
    else
    {
        printf("Deallocated Memory block %d\n",stack[top]);
        stack[top--];
    }
}

void display()
{
    if(top == -1){
        printf("No memory block is currently allocated.\n");
        return ;
    }
    printf("Currently Allocated memory block \n");
    for(int i=0;i<top;i++)
        printf("%d ",stack[i]);
    printf("\n");
}

int main()
{
    int choice,blockid;
   
    while(1)
    {
        printf("1.Allocate Memoryblock\n 2.Deallocate Memoryblock\n 3.Display\n 4.Exit\n");
        printf("Enter the choice :\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            printf("Enter the blockid :\n");
            scanf("%d",&blockid);
            allocateMemory(blockid);
            break;
            
            case 2:
            deallocateMemory();
            break;
            
            case 3:
            display();
            break;
            
            case 4:
            printf("Exit.\n");
            exit(0);
            
            default:
            printf("Invalid Choice.\n");
        }
    }
}
