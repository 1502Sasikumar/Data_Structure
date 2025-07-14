//doubly linked list and a target sum x, to find all unique pairs of nodes whose data values add up to x
#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *prev;
  struct node *next;
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
  if(head==NULL){
    head=tail=newnode;
  }
  else
  {
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
  }
}
void findpairs(int x)
{
  struct node *left=head;
  struct node *right=tail;
  int found=0;
  
  while(left!=NULL && right!=NULL && left!=right && right->next!=left)
  {
    int sum=left->data + right->data;
    
    if(sum==x){
      printf("%d %d\n",left->data,right->data);
      found=1;
      left=left->next;
      right=right->prev;
    }
    else if(sum<x){
      left=left->next;
    }
    else{
      right=right->prev;
    }
    
  }
  if(!found){
    printf("No pair found\n");
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
  int x;
  scanf("%d",&x);
  findpairs(x);
  
}
