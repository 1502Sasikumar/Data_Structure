//To create Hash Table
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
// Doubly linked list node
struct Node {
    int key;
    int value;
    struct Node* next;
    struct Node* prev;
};
//Hash Table: array of pointers to NOde 
struct Node* hashTable[SIZE]={NULL};

//HASH Function
int hashFunction(int key){//1
    return key % SIZE;//1%10= 1
}
// Create a new node
struct Node* createNode(int key, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
//Insert key-value pair into hashTable
void insert(int key, int value){//1-100
    int index=hashFunction(key);//1 
    struct Node* newNode=createNode(key, value);
    if(hashTable[index]==NULL){
        hashTable[index]=newNode;}
    else{
        struct Node* temp=hashTable[index];//ht[1]=1000
        //check for existing and move to last 
        while(temp!=NULL){
            if(temp->key==key){
                temp->value=value;
                free(newNode);return;
            }
            if(temp->next==NULL) break;
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
}
// Display the hash table
void display() {
    for (int i = 0; i < SIZE; i++) {
        struct Node* temp = hashTable[i];
        printf("[%d]: ", i);
        while (temp != NULL) {
            printf("(%d:%d) <-> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main(){
    insert(1,100);insert(2,200);insert(3,300);
    display();
    insert(1,400);
    display();
}
