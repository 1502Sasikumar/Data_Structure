// Delete a node based on values
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insertAtEnd(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void delbyvalue(int data) {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Search for the node
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node is not found\n");
        return;
    }

    // Case 1: Node is head
    if (temp == head) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    }
    // Case 2: Node in middle or end
    else {
       // if (temp->next != NULL)
            temp->next->prev = temp->prev;
      //  if (temp->prev != NULL)
            temp->prev->next = temp->next;
    }

    printf("Deleted value is %d\n", data);
    free(temp);
}

void display() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, data;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &data);
        insertAtEnd(data);
    }

    display();

    int delvalue;
    printf("Enter the value to delete: ");
    scanf("%d", &delvalue);

    delbyvalue(delvalue);

    display();

    return 0;
}
