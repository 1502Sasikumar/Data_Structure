//C program to implement a tree to identify the car manufacturer and car type by providing car name
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[100];
    char manufact[100];
    char type[100];
    struct node *left;
    struct node *right;
};

struct node* createnode(char name[], char manufact[], char type[]) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    strcpy(newnode->name, name);
    strcpy(newnode->manufact, manufact);
    strcpy(newnode->type, type);
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, char name[], char manufact[], char type[]) {
    if (root == NULL) {
        return createnode(name, manufact, type);
    }
    if (strcmp(name, root->name) < 0) {
        root->left = insert(root->left, name, manufact, type);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insert(root->right, name, manufact, type);
    }
    return root;
}

struct node* search(struct node* root, char name[]) {
    if (root == NULL) {
        printf("Car not found!\n");
        return NULL;
    }

    int cmp = strcmp(name, root->name);

    if (cmp == 0) {
        printf("\nCar Found:\n");
        printf("Name        : %s\n", root->name);
        printf("Manufacturer: %s\n", root->manufact);
        printf("Type        : %s\n", root->type);
        return root;
    } else if (cmp < 0) {
        return search(root->left, name);
    } else {
        return search(root->right, name);
    }
}

void inorder(struct node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%s | %s | %s\n", root->name, root->manufact, root->type);
    inorder(root->right);
}

int main() {
    struct node *root = NULL;

    root = insert(root, "Swift", "Maruti Suzuki", "Hatchback");
    root = insert(root, "Creta", "Hyundai", "SUV");
    root = insert(root, "City", "Honda", "Sedan");
    root = insert(root, "Fortuner", "Toyota", "SUV");
    root = insert(root, "XUV700", "Mahindra", "SUV");
    root = insert(root, "Tiago", "Tata Motors", "Hatchback");
    root = insert(root, "Verna", "Hyundai", "Sedan");
    root = insert(root, "Baleno", "Maruti Suzuki", "Hatchback");

    printf("Car Identification System\n\n");
    printf("Cars in Database (Inorder Traversal):\n");
    inorder(root);

    char carname[50];
    printf("\nEnter the car name to be searched: ");
    scanf("%s", carname);

    search(root, carname);

    return 0;
}
