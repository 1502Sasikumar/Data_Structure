//Insertion Sort using Media Files
#include<stdio.h>
#include<string.h>

#define MAX_FILE 100
#define MAX_LEN 100

void insertionsort(char files[][MAX_LEN],int n){
    char temp[MAX_LEN];
    int j;
    for(int i=1; i<n; i++){
        strcpy(temp,files[i]);
         j=i-1;
    
    while(j>=0 && strcmp(files[j],temp)>0){
        strcpy(files[j+1],files[j]);
        j--;
    }
    strcpy(files[j+1],temp);
    }
}
int main()
{
    char files[MAX_FILE][MAX_LEN];
    int n;
    
    printf("Enter the Media to ADD:");
    scanf("%d",&n);
    
   
    for(int i=0; i<n; i++){
        printf("Enter the Media Name:");
        scanf("%s",files[i]);
    }
    insertionsort(files,n);
    for(int i=0; i<n; i++){
        printf("%s\n",files[i]);
    }
}
