//Token generation in hospital using pthread
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int done = 0;

struct node {
    int token;
    struct node *next;
};

struct node *front = NULL;
struct node *rear  = NULL;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void enqueue(int token)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->token = token;
    newnode->next  = NULL;

    pthread_mutex_lock(&lock);

    if (front == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;    
        rear = newnode;
    }

    pthread_mutex_unlock(&lock);
}

int dequeue()
{
    pthread_mutex_lock(&lock);

    if (front != NULL) {
        struct node *temp = front;
        printf("\nToken Number : %d\n", temp->token);
        front = front->next;
        if (front == NULL)
            rear = NULL;

        free(temp);

        pthread_mutex_unlock(&lock);
        return 1;
    }

    pthread_mutex_unlock(&lock);
    return 0;
}

void* Producer(void *arg)
{
    char c;
    while (1)
    {
        printf("Press T or t for Token OR Press Q or q for Quit: ");
        scanf(" %c", &c); 

        if(c == 'T' || c == 't'){
            int token = rand() % 100;
            enqueue(token);
        }
        else if(c == 'Q' || c == 'q'){
            pthread_mutex_lock(&lock);
            done = 1;
            pthread_mutex_unlock(&lock);
            break;
        }
    }
    return NULL;
}

void* Consumer(void *arg)
{
    while(1)
    {
        if (dequeue()) {
            sleep(2);
        } else {
            pthread_mutex_lock(&lock);
            int local_done = done;
            pthread_mutex_unlock(&lock);

            if (local_done) break;
            sleep(1);
        }
    }
    printf("Consumer Exiting..\n");
    return NULL;
}

int main()
{
    srand(getpid());

    pthread_t sender, receiver;

    pthread_create(&sender, NULL, Producer, NULL);
    pthread_create(&receiver, NULL, Consumer, NULL);

    pthread_join(sender, NULL);
    pthread_join(receiver, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}
