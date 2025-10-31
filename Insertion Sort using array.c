//Insertion Sort using array
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d",& a[i]);
    }
    for(int i=1; i<n; i++){
        int temp=a[i];
        int j=i-1;
        
        while(a[j] >=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
}
