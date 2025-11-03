// Find Middle element in the linkedlist
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

void MiddleElement() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *slow = head;
    struct node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle Element : %d\n", slow->data);
}

void display() {
    struct node *temp = head;
    while (temp != NULL) {
       // printf("%d ", temp->data);
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
    MiddleElement();
    display();
    return 0;
}
