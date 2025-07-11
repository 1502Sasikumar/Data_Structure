//Audio playlist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char song[100];
    struct node *next;
};

struct node *head = NULL;

struct node* createnode(char song[]) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    strcpy(newnode->song, song);
    newnode->next = NULL;
    return newnode;
}

void addsong(char song[]) {
    struct node* newnode = createnode(song);
    newnode->next = head;
    head = newnode;
    printf("%s added to the playlist\n", song);
}

void display() {
    if (head == NULL) {
        printf("Playlist is Empty\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->song);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    char songname[100];
    while (1) {
        printf("\nChoice 1: Add song\nChoice 2: Display Songs\nChoice 3: Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                printf("Enter the Song:\n");
                fgets(songname, sizeof(songname), stdin);
                songname[strcspn(songname, "\n")] = 0; 
                addsong(songname);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
