// Quick sort
#include<stdio.h>

int parition(int arr[],int lb,int ub){
    int start=lb;
    int pivot=arr[lb];
    int end=ub;
    while(start<end){
        while(arr[start] <= pivot){
            start++;
        }
        while(arr[end] > pivot){
            end--;
        }
        if(start<end){
            int t=arr[start];
            arr[start]=arr[end];
            arr[end]=t;
        }
    }
    int t=arr[lb];
    arr[lb]=arr[end];
    arr[end]=t;
    
    return end;
}
void quicksort(int arr[],int lb,int ub){
    
    if(lb < ub){
    int loc=parition(arr,lb,ub);
    quicksort(arr,lb,loc-1);
    quicksort(arr,loc+1,ub);
    
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
}
    
