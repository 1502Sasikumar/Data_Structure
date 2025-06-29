#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Insert at the end 
void insertAtEnd(struct node **head, int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (*head == NULL) {
        *head = newnode;
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

// Create matrix 
void creating_matrix(struct node **head, int rows, int cols, char name) {
    int value;
    printf("Enter the Elements of Matrix %c (%dx%d):\n", name, rows, cols);
    for (int i = 0; i < rows * cols; i++) {
        scanf("%d", &value);
        insertAtEnd(head, value);
    }
}

// Add two matrices 
void addTwoMatrices(struct node *head1, struct node *head2, struct node **result) {
    while (head1 != NULL && head2 != NULL) {
        insertAtEnd(result, head1->data + head2->data);
        head1 = head1->next;
        head2 = head2->next;
    }
}

// Display matrix 
void display(struct node *head, int rows, int cols) {
    struct node *temp = head;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (temp != NULL) {
                printf("%d ", temp->data);
                temp = temp->next;
            }
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    struct node *matrixA = NULL, *matrixB = NULL, *matrixSum = NULL;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    creating_matrix(&matrixA, rows, cols, 'A');
    creating_matrix(&matrixB, rows, cols, 'B');

    addTwoMatrices(matrixA, matrixB, &matrixSum);

    printf("\nMatrix A:\n");
    display(matrixA, rows, cols);

    printf("\nMatrix B:\n");
    display(matrixB, rows, cols);

    printf("\nSum of Matrices:\n");
    display(matrixSum, rows, cols);

    return 0;
}

