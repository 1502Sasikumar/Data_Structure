// Find Mid Element of list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void add(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        return;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Corrected: returns a node pointer, does not return inside loop
struct node* search()
{
    struct node *slow = head;
    struct node *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void display()
{
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n) {
        int data;
        scanf("%d", &data);
        add(data);
        n--;
    }

    struct node *middle = search();
    printf("Middle element: %d\n", middle->data);

    
    return 0;
}
