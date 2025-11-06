//Pthread using Binary search
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX 100
#define NAMES 5

// Shared Data
char names[NAMES][MAX];
char target[MAX];
int foundIndex = -1;  
pthread_mutex_t lock;

struct ThreadData {
    int low;
    int high;
};

void* binarySearch(void* arg) {
    struct ThreadData *data = (struct ThreadData*)arg;
    int low = data->low;
    int high = data->high;

    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(names[mid], target);

        if (cmp == 0) {
            pthread_mutex_lock(&lock);
            foundIndex = mid;
            pthread_mutex_unlock(&lock);
            pthread_exit(NULL); 
        }
        else if (cmp > 0)
            high = mid - 1;
        else
            low = mid + 1;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;
    struct ThreadData d1, d2;

    pthread_mutex_init(&lock, NULL);

    
    strcpy(names[0], "Algorithms");
    strcpy(names[1], "Artificial Intelligence");
    strcpy(names[2], "Circuit Theory");
    strcpy(names[3], "Data Structures");
    strcpy(names[4], "Digital Electronics");
 

    printf("Enter the name to search: ");
    fgets(target, MAX, stdin);
    target[strcspn(target, "\n")] = '\0'; 

    d1.low = 0;
    d1.high = (NAMES / 2) - 1;
    d2.low = NAMES / 2;
    d2.high = NAMES - 1;

    pthread_create(&t1, NULL, binarySearch, &d1);
    pthread_create(&t2, NULL, binarySearch, &d2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);


    if (foundIndex != -1)
        printf("\n %s' found at position %d (index %d)\n", target, foundIndex + 1, foundIndex);
    else
        printf("\n s' not found in the list.\n", target);

    pthread_mutex_destroy(&lock);
    return 0;
}
