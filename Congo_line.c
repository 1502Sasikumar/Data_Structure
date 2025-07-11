//Congo line
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{             // structure declaration
    char *name;
    struct node* prev;
    struct node*next;
};

struct node*head=NULL;  // head declaration
struct node*tail=NULL;  // tail declaration

void join_queue(char *name){        // insert at end function
    struct node *newnode=(struct node*)malloc(sizeof(struct node*)); 
    newnode->name=(char*)malloc(strlen(name)+1);  
    strcpy(newnode->name,name);     
    if(tail!=NULL){        
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
        newnode->next=NULL;
    }
    else{                 // initial node
        head=newnode;
        tail=newnode;
        newnode->next=NULL;
        newnode->prev=NULL;
    }
}

void leave_queue(){         // delete at begining
    struct node* temp=head;
    head=temp->next;
    free(temp); 
    head->prev=NULL;
}

void view_queue(){         // display
    struct node*temp=head;
    while(temp!=NULL){
        printf("\n%s\n || ",temp->name);
        temp=temp->next;
    }
    printf("\nNULL\n");
}

int main()
{
  join_queue("Naveen");
  join_queue("Siran");
  join_queue("Sasi");
  view_queue();
  leave_queue();
  view_queue();
  join_queue("Niyamath");
  join_queue("Arshad");
}
