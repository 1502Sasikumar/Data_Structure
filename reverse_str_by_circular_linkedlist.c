// circular linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data;
    struct node *next;
};

// InsertAtEnd
void insertAtEnd(struct node **tail, char data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    if (*tail == NULL) {
        newnode->next = newnode;
        *tail = newnode;
    } else {
        newnode->next = (*tail)->next;
        (*tail)->next = newnode;
        *tail = newnode;
    }
}

// display
void display(struct node *tail) {
    if (tail == NULL) {
        printf("List is Empty.\n");
        return;
    } else {
        struct node *temp = tail->next;
        do {
            printf("%c ", temp->data);
            temp = temp->next;
        } while (temp != tail->next);
        printf("\n");
    }
}

// sorting
void sortlist(struct node **tail) {
    if (*tail == NULL)
        return;
    else {
        struct node *current, *index;
        current = (*tail)->next;
        char temp;
        do {
            index = current->next;
            while (index != (*tail)->next) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        } while (current != (*tail)->next);
    }
}

int main() {
    struct node *tail = NULL;
    char name[100];
    printf("Enter the Name: ");
    fgets(name, sizeof(name), stdin);

    

    for (int i = 0; i < strlen(name); i++) {
        insertAtEnd(&tail, name[i]);
    }

    printf("\nOriginal circular linked list:\n");
    display(tail);

    sortlist(&tail);

    printf("\nSorted circular linked list:\n");
    display(tail);
    return 0;
}

