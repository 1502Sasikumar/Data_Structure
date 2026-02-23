// Find the 3rd node from last in a linked list
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertAtEnd(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void findthreefromlast()
{
    if(head==NULL){
        printf("List is Empty\n");
        return;
    }
    struct node *first=head;
    struct node *second=head;
    
    for(int i=0; i<3; i++){
        if(first==NULL){
            printf("Less than 3 Nodes\n");
            return;
        }
        first=first->next;
    }
    while(first!=NULL){
        first=first->next;
        second=second->next;
    }
    printf("%d\n",second->data);
}

void display() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, data;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&data);
        insertAtEnd(data);
    }

    //display();
    findthreefromlast();
  //  display();
    return 0;
}
