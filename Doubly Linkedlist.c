//Double complete program
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;

void insertAtBeg(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    
    if(head==NULL){
        head=tail=newnode;
    }
    else
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}
void insertAtEnd(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
     newnode->data=data;
     newnode->prev=NULL;
     newnode->next=NULL;
     
     if(head==NULL){
         head=tail=newnode;
     }
     else{
        tail->next=newnode;
        newnode->prev=tail;
     }
     tail=newnode;
     
}
void delAtBeg()
{
    struct node *temp=head;
    if(head==NULL){
        printf("List is Empty\n");
        return;
    }
    head=temp->next;
    free(temp);
    head->prev=NULL;
}
void delAtEnd()
{
    struct node *temp=tail;
    if(tail==NULL){
        printf("List is Empty\n");
        return;
    }
    tail=tail->prev;
    tail->next=NULL;
    free(temp);
}
void insertAtMiddle(int data, int pos)
{
    if(pos==1){
        insertAtBeg(data);
        return;
    }
    struct node *temp=head;
    
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    
    for(int i=1; temp!=NULL && i<pos-1; i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=newnode;
    }
    temp->next=newnode;
}
void delAtPos(int pos){
    struct node *temp=head;
    if(head==NULL){
        printf("List is Empty\n");
        return;
    }
    if(pos==1){
        delAtBeg();
        return;
    }
    for(int i=1; temp!=NULL && i<pos; i++)
        temp=temp->next;
    
    if(temp==NULL){
        printf("Position Invalid\n");
        return;
    }
    else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        temp->prev=temp->next=NULL;
    }
    free(temp);
}
void display()
{
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main()
{
    // insertAtBeg(10);
    // insertAtBeg(20);
    // insertAtBeg(30);
     insertAtBeg(40);
    insertAtEnd(50);
    insertAtEnd(60);
    insertAtEnd(70);
    display();
    // delAtBeg();
    // delAtBeg();
    // display();
    // delAtEnd();
    // delAtEnd();
    // display();
    // insertAtMiddle(100,3);
    // display();
    delAtPos(2);
    display();
}
