//1.Add at End, print Elements in both forward and reverse direction
#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
  struct node *prev;
};
struct node *head=NULL;
struct node *tail=NULL;

struct node *createnode(int data)
{
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=data;
  newnode->prev=NULL;
  newnode->next=NULL;
  return newnode;
}
void insertAtEnd(int data){
  struct node *newnode=createnode(data);
  if(head==NULL)
  {
    head = tail = newnode;
    return;
  }
  else
  {
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
  }
}

void displayforward()
{
  if(head==NULL){
    printf("Empty\n");
    return;
  }
  struct node *temp=head;
  while(temp!=NULL){
    printf("%d",temp->data);
    if(temp->next!=NULL){
      printf(" ");
    }
    temp=temp->next;
  }
  printf("\n");
}
void displayreverse()
{
  if(head==NULL){
    printf("Empty\n");
    return;
  }
  struct node *temp=tail;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->prev;
  }
  //printf("\n");
}
int main()
{
  int n;
  scanf("%d",&n);
  while(n--)
  {
    int data;
    scanf("%d",&data);
    insertAtEnd(data);
    
  }
  displayforward();
  displayreverse();
  
  
}
