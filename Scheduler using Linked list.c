//Scheduler using Linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int id;
    char taskname[50];
    int bursttime;
    struct node *next;
};
struct node *head = NULL;

struct node *createnode(int id, char taskname[], int bursttime) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->id = id;
    newnode->bursttime = bursttime;
    strcpy(newnode->taskname, taskname);
    newnode->next = NULL;
    return newnode;
}

void addtask(int id, char taskname[], int bursttime) {
    struct node *newnode = createnode(id, taskname, bursttime);
    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Task %d (%s) added to the Scheduler\n", id, taskname);
}

void display() {
    if (head == NULL) {
        printf("No tasks in the scheduler.\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL) {
        printf("ID: %d\tTaskname: %s\tBurst time: %d\n", temp->id, temp->taskname, temp->bursttime);
        temp = temp->next;
    }
    printf("NULL\n");
}

void runScheduler() {
    if (head == NULL) {
        printf("No task to run.\n");
        return;
    }

    struct node *temp=head;
    while (head != NULL) {
        temp = head;
        printf("Running task %d (%s) - burst time %d\n", temp->id, temp->taskname, temp->bursttime);
        head = head->next;
        free(temp);
    }
    printf("All tasks completed.\n");
}

int main() {
    addtask(1, "Task A", 10);
    addtask(2, "Task B", 20);
    addtask(3, "Task C", 30);

    printf("\nCurrent Task List:\n");
    display();

    printf("\nRunning Scheduler:\n");
    runScheduler();

    printf("\nAfter running all tasks:\n");
    display();

    return 0;
}
