//Undo Operation using stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACTIONS 100
#define MAX_LENGTH 100

// Stack to hold actions
char* stack[MAX_ACTIONS];
int top = -1;

// Push an action to the stack
void push(char* action) {
    if (top >= MAX_ACTIONS - 1) {
        printf("Undo stack overflow!\n");
        return;
    }
    stack[++top] = strdup(action); // Copy string to heap
    printf("Action performed: %s\n", action);
}

// Pop (undo) the last action
void undo() {
    if (top == -1) {
        printf("Nothing to undo.\n");
        return;
    }
    printf("Undoing: %s\n", stack[top]);
    free(stack[top--]); // Free memory and move top
}

// Display current stack (for debug)
void displayStack() {
    if (top == -1) {
        printf("No actions performed yet.\n");
        return;
    }
    printf("Action history:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d: %s\n", i + 1, stack[i]);
    }
}

int main() {
    int choice;
    char action[MAX_LENGTH];

    while (1) {
        printf("\n--- Undo Operation Menu ---\n");
        printf("1. Perform Action\n");
        printf("2. Undo Last Action\n");
        printf("3. Show Action History\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                printf("Enter action (e.g., Insert 'A', Delete 'B'): ");
                fgets(action, MAX_LENGTH, stdin);
                action[strcspn(action, "\n")] = '\0'; // Remove newline
                push(action);
                break;
            case 2:
                undo();
                break;
            case 3:
                displayStack();
                break;
            case 4:
                // Cleanup before exit
                while (top >= 0) {
                    free(stack[top--]);
                }
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
