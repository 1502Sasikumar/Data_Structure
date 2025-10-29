//string reverse using Linkedlist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char ch;
    struct node *next;
};
struct node *head = NULL;

void reverse(char c) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->ch = c;
    newnode->next = head;  // Insert at the beginning
    head = newnode;
}

void display() {
    struct node *temp = head;
    printf("Reversed string: ");
    while (temp != NULL) {
        printf("%c", temp->ch);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    char str[100];
    printf("Enter the string to reverse: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    for (int i = 0; i < strlen(str); i++) {
        reverse(str[i]);
    }

    display();
    return 0;
}
