// 1.Add at Begin 2.Add at End 3.Add at position
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

void insertAtBeg(int data)
{
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=data;
  
  if(head==NULL)
  {
    head = tail = newnode;
    newnode->prev=NULL;
    newnode->next=NULL;
  }
  else
  {
    struct node *temp=head;
    newnode->next=head;
    temp->prev=newnode;
    head=newnode;
    
  }
  
}
void insertAtEnd(int data)
{
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=data;
  
  if(head==NULL)
  {
    head = tail = newnode;
    newnode->prev=NULL;
    newnode->next=NULL;
  }
  else
  {
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
  }
  
}

void insertAtpos(int data,int pos)
{
  if(pos==1){
  insertAtBeg(data);
  return;
  }
  
  struct node *temp=head;
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=data;
  
  pos--;
  while(pos > 1 && temp!=NULL){
    temp=temp->next;
    pos--;
  }
  
  if(temp==NULL)
  return;
  newnode->next=temp->next;
  newnode->prev=temp;
  
  if(temp->next!=NULL)
  {
    temp->next->prev=newnode;
  }
  temp->next=newnode;
}

void display()
{
  struct node *temp=head;
  while(temp!=NULL)
  {
    printf("%d",temp->data);
    if(temp->next!=NULL)
      printf(" ");
    temp=temp->next;
  }
  printf("\n");
}

int main()
{
  int n,choice,pos,data;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&choice);
    
    if(choice==1){
      scanf("%d",&data);
      insertAtBeg(data);
    }
    else if(choice==2){
      scanf("%d",&data);
      insertAtEnd(data);
    }
    else if(choice==3)
    {
      scanf("%d %d",&data,&pos);
      insertAtpos(data,pos);
    }
    display();
  }
  return 0;
}
