//Insert At middle if the nodes odd insert at center and if it is even insert at middle of the list
#include<stdio.h>
#include<stdlib.h>

struct node 
{
  int data;
  struct node *next;
};
struct node *head=NULL;

struct node *createnode(int data)
{
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=data;
  newnode->next=NULL;
  return newnode;
}

void insertAtEnd(int data)
{
  struct node *newnode=createnode(data);
  if(head==NULL)
  {
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

int countofnodes()
{
  int count = 0;  
  struct node *temp=head;
  while(temp!=NULL)
  {
    count++;
    temp=temp->next;
  }
  return count;
}

void insertAtPos(int data,int pos)  
{
  struct node *newnode=createnode(data);
  if(pos==0)
  {
    newnode->next=head;
    head=newnode;
    return;
  }
  struct node *temp=head;
  for(int i=0;i<pos-1 && temp!=NULL;i++){
    temp=temp->next;
  }
  if(temp==NULL)
  return;
  
  newnode->next=temp->next;
  temp->next=newnode;
}

void display()
{
  struct node *temp=head;
  while(temp!=NULL)
  {
    printf("%d ",temp->data);
    temp=temp->next;
  }
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
  
  int a;
  scanf("%d",&a);
  int count = countofnodes();
  int pos;
  if(count % 2 == 0)
  {
    pos = count / 2;
  }
  else
  {
    pos = count / 2;
  }
  insertAtPos(a,pos);  
  display();
}
