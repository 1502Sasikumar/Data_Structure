// program to reverse the Number
#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *prev;
  struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;

void insert(int data)
{
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=data;
  newnode->prev=NULL;
  newnode->next=head;
  head=newnode;
}

void display()
{
  if(head==NULL){
    printf("Empty\n");
    return;
  }
  struct node *temp=head;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
}
int main()
{
  int n;
  scanf("%d",&n);
  while(n--){
    int data;
    scanf("%d",&data);
    insert(data);
  }
  display();
}
