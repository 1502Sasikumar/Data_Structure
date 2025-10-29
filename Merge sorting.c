//Merge sort
#include<stdio.h>
void merge(int a[],int lb,int mid,int ub);
void mergesort(int a[],int lb,int ub){
    if(lb<ub){
        int mid =(lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}
void merge(int a[],int lb, int mid, int ub){
    int i=lb;
    int j=mid+1;
    int k=lb;
    int temp[ub+1];
    
    while(i<=mid && j<=ub){
        if(a[i] < a[j]){
            temp[k]=a[i];
            i++;
        }
        else
        {
            temp[k]=a[j];
            j++;
        }
        k++;
    }
    
     while(j<=ub){
        temp[k]=a[j];
        j++;
        k++;
    }
    
    while(i<=mid){
        temp[k]=a[i];
        i++;
        k++;
    }
  
    for(int i=lb; i<=ub; i++){
        a[i]=temp[i];
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
}
