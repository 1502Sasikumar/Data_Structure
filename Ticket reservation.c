// Ticket reservation
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include<string.h>
struct node {
    char * name;
    char prio;
    int token;
	struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void enqueue(char * name,char prio,int token) {
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->name=(char*)malloc(strlen(name)+1);
	              strcpy(newnode->name,name);
	newnode->prio=prio;
	newnode->token = token;
	newnode->next = NULL;

	pthread_mutex_lock(&lock);
	if (rear == NULL) {
		front = rear = newnode;
	} else {
		if(newnode->prio=='y') {
			newnode->next=front;
			front=newnode;
		}
		else {
			rear->next = newnode;
			rear = newnode;
		}
	}
	pthread_mutex_unlock(&lock);
}

int dequeue() {
	pthread_mutex_lock(&lock);
	if (front != NULL) {
		struct node* temp = front;
		if(temp->prio=='y')
		printf("\nServing PRIORITY Customer: %s (Token %d)\n",temp->name,temp->token);
		else if(temp->prio=='n')
		printf("\nServing NORMAL Customer: %s (Token %d)\n",temp->name,temp->token);
		front = front->next;
		if (front == NULL) rear = NULL;
		free(temp->name);
		free(temp);
		pthread_mutex_unlock(&lock);
		return 1;
	}
	else {
		printf("\nNo more customers in queue. Waiting...");
			pthread_mutex_unlock(&lock);
		return 0;
	}
}

void* producer(void* arg) {
	char prio,name[25];
	int n=3;
	while (n) {
		printf("\nEnter customer name: ");
		scanf(" %[^\n]",name);
		printf("\nIs this a priority customer? (y/n): ");
		scanf(" %c",&prio);
		int token = rand() % 100;
		enqueue(name,prio,token);
	n--;
	    
	}
	pthread_exit(NULL);
	return NULL;
}

void* consumer(void* arg) {
	while (1) {
		if (dequeue()) {
			sleep(10);
		} else {
			pthread_mutex_lock(&lock);
		//	int local_done = done;
			break;
			pthread_mutex_unlock(&lock);
		//	if (local_done) break;
			//sleep(10);
		}
	}
	printf("Consumer exiting.\n");
	pthread_exit(NULL);
	return NULL;
}

int main() {
	srand(getpid());

	pthread_t sender, receiver;
	pthread_create(&sender, NULL, producer, NULL);
		pthread_join(sender, NULL);

	pthread_create(&receiver, NULL, consumer, NULL);

	pthread_join(receiver, NULL);

	pthread_mutex_destroy(&lock);
	return 0;
}
