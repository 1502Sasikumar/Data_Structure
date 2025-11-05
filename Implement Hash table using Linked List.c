//Implement Hash table using Linked List
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct node {
    int key;
    int value;
    struct node *next;
};

struct node *hashTable[TABLE_SIZE]; // global hash table

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Create a new node
struct node *createNode(int key, int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->key = key;
    newnode->value = value;
    return newnode;
}

// Insert function
void insert(int key, int value) {
    int index = hashFunction(key);
    struct node *newnode = createNode(key, value);

    if (hashTable[index] == NULL) {
        hashTable[index] = newnode;
    } else {
        struct node *temp = hashTable[index];
        while (temp->next != NULL) {
            if (temp->key == key) {  // update existing key
                temp->value = value;
                free(newnode);
                printf("Updated existing key %d with new value %d at index %d\n", key, value, index);
                return;
            }
            temp = temp->next;
        }

        // Check last node also
        if (temp->key == key) {
            temp->value = value;
            free(newnode);
            printf("Updated existing key %d with new value %d at index %d\n", key, value, index);
            return;
        }

        temp->next = newnode;
    }
    printf("Inserted key %d at index %d\n", key, index);
}

// Search function
void search(int key) {
    int index = hashFunction(key);
    struct node *temp = hashTable[index];
    
    while (temp != NULL) {
        if (temp->key == key) {
            printf("Key %d found with value %d (at index %d)\n", key, temp->value, index);
            return;
        }
        temp = temp->next;
    }
    printf("Key %d is not found in hash table\n", key);
}

// Delete function
void delete(int key) {
    int index = hashFunction(key);
    struct node *temp = hashTable[index];
    struct node *prev = NULL;
    
    while (temp != NULL && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key %d is not found\n", key);
        return;
    }

    if (prev == NULL) {
        hashTable[index] = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Key %d is deleted from index %d\n", key, index);
}

// Display function
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        struct node *temp = hashTable[i];
        while (temp != NULL) {
            printf("-> [Key:%d, Val:%d] ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, key, value;

    while (1) {
        printf("\n=== Hash Table Menu ===\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key and value: ");
                scanf("%d %d", &key, &value);
                insert(key, value);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(key);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
