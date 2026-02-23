//Complte singly LinkedList 
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertAtEnd(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
        return;
    }

    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertAtBegin(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}
void delAtBeg(){
    struct node *temp=head;
    if(head==NULL)
        printf("List is Empty\n");
    head=head->next;
    free(temp);
}
void delAtEnd(){
    if(head == NULL){
        printf("List is Empty\n");
        return;
    }

    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}
void insertAtMiddle(int data, int pos){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    
    if(pos==1){
        newnode->next=head;
        head=newnode;
    }
    struct  node *temp=head;
    for(int i=1; i<pos-1; i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    
}
void delAtPos(int pos){
    if(head==NULL){
        printf("List is Empty\n");
        return;
    }
    struct node *temp=head;
    if(pos==1){
        head=temp->next;
        free(temp);
        return;
    }
    for(int i=1; temp!=NULL && i<pos-1; i++){
        temp=temp->next;
    }
    if(temp==NULL || temp->next==NULL){
        printf("Position invalid\n");
        return;
    }
    struct node *notetodel=temp->next;
    temp->next=notetodel->next;
    free(notetodel);
    return;
    
}
void display(){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtBegin(40);
    insertAtBegin(50);
    insertAtBegin(60);
    
    // delAtBeg();
    // delAtBeg();
    
    // delAtEnd();
    insertAtMiddle(70,3);
    display();
    delAtPos(5);
    display();
    delAtPos(4);
    
    display();
}
