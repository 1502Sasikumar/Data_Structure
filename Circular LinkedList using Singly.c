// Circular Linked List
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;

struct node *Createnode(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
    
}

void insertAtEnd(int data){
    struct node *newnode=Createnode(data);
    
    if(head==NULL){
        head=newnode;
        newnode->next=head;
        return;
    }
    struct node *temp=head;
    
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
}

void insertAtBegin(int data){
    struct node *newnode=Createnode(data);
    
    if(head==NULL){
        newnode->next=newnode;
        head=newnode;
        return;
    }
    struct node *temp=head;
    
    while(temp->next!=head){
        temp=temp->next;
    }
    newnode->next=head;
    temp->next=newnode;
    head=newnode;
}
void delAtBegin()
{
    if(head==NULL){
        printf("Node is Empty\n");
        return;
    }
    
    struct node *temp=head;
    if(head->next == head){
        free(head);
        head=NULL;
        return;
    }
    
    struct node *last=head;
    while(last->next != head){
        last=last->next;
    }
    head=head->next;
    last->next=head;
    free(temp);
    
}

void delAtEnd(){
    
    if(head==NULL){
        printf("Node is Empty\n");
        return;
    }
    struct node *temp=head;
    
    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }
    while(temp->next->next!=head){
        temp=temp->next;
    }
    struct node *last=temp->next;
    temp->next=head;
    free(last);
    
}
void display()
{
    struct node *temp=head;
    if(head==NULL){
        printf("Node is Empty\n");
        return;
    }
    do{
        printf("%d ->",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("NULL\n");
}
int main()
{
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    display();
    
    insertAtEnd(40);
    insertAtEnd(50);
    display();
    
    insertAtBegin(7);
    insertAtBegin(8);
    display();
    
    delAtBegin();
    display();
    
    delAtEnd();
    display();
}
