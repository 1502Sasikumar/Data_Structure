// Binary search using array
#include<stdio.h>

int binarysearch(int a[],int lb, int ub, int target){
    if(lb < ub){
        int mid = (lb+ub)/2;
        if(a[mid] == target){
            return mid;
        }
        else if(a[mid] > target){
            return binarysearch(a,lb,mid-1,target);
        }
        else
            return binarysearch(a,mid+1,ub,target);
    }
    return -1;
}
int main()
{
    int n,target;
    scanf("%d",&n);
    
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the target:");
    scanf("%d",&target);
    binarysearch(a,0,n-1,target);
    printf("%d",target);
    
}
