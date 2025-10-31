// C program to sort the media file according to the file names using insertion sort
#include<stdio.h>
#include<string.h>

void insertionsort(char files[][100],int n){
    for(int i=1; i<n; i++){
    char temp[100];
    strcpy(temp,files[i]);
    int j=i-1;
    
    while(j >=0 && strcmp(files[j], temp) > 0){
        strcpy(files[j+1],files[j]);
        j--;
    }
    strcpy(files[j+1],temp);
    }
}

int main()
{
    int n;
    printf("Enter the no. of Media files:");
    scanf("%d",&n);
    getchar();
    
    char files[n][100];
    for(int i=0; i<n; i++){
        scanf("%s",files[i]);
    }
    insertionsort(files,n);
    
    for(int i=0; i<n; i++){
        printf("%s ",files[i]);
    }
}
