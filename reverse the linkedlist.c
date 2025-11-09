// reverse the linkedlist
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

void insert(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void reverse()
{
    struct node *curr=head;
    struct node *temp1=NULL;
    struct node *temp2=NULL;
    while(curr!=NULL){
        temp2=curr->next;
        curr->next=temp1;
        temp1=curr;
        curr=temp2;
    }
    head=temp1;
}
void display()
{
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    int n;
    scanf("%d",&n);
    int data;
    while(n--){
        scanf("%d",&data);
        insert(data);
    }
    reverse();
    display();
}
