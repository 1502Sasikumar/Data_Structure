//Scavenger hunt using linkedlist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char clue[100];
    struct Node* next;
};

struct Node* createNode(char *msg) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->clue, msg);
    newNode->next = NULL;
    return newNode;
}


void startHunt(struct Node* head) {
    struct Node* current = head;
    int step = 1;

    while (current != NULL) {
        printf("\nClue %d: %s\n", step, current->clue);

        if (current->next != NULL) {
            printf("Press Enter to go to the next clue...");
            getchar();
        }
        
        current = current->next;
        step++;
    }

    printf("\n Congratulations! You found the TREASURE! \n");
}

int main() {
    struct Node *clue1, *clue2, *clue3, *clue4;

    // Creating clues
    clue1 = createNode("Go to the main entrance of the college.");
    clue2 = createNode("Look under the bench near the playground.");
    clue3 = createNode("Search inside the library near C programming section.");
    clue4 = createNode("Final hint: The treasure is in the lab drawer!");

    clue1->next = clue2;
    clue2->next = clue3;
    clue3->next = clue4;

    startHunt(clue1);

    return 0;
}
