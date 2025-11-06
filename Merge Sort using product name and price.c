//Merge Sort using product name and price
#include<stdio.h>
#include<string.h>

struct product
{
    char name[50];
    float price;
};
void merge(struct product p[],int lb,int mid,int ub,struct product temp[]){
    int i=lb;
    int j=mid+1;
    int k=lb;
    
    while(i<=mid && j<=ub){
        if(p[i].price < p[j].price){
            temp[k]=p[i];
            i++;
            k++;
        
        }
        else{
            temp[k]=p[j];
            j++;
            k++;
        }
    }
    if(i <= mid){
        temp[k]=p[i];
        i++;
        k++;
    }
    else if(j <= ub){
        temp[k]=p[j];
        j++;
        k++;
    }
    for(int x=lb; x<=ub; x++){
        p[x]=temp[x];
    }
    
}
void mergesort(struct product p[],int lb,int ub,struct product temp[]){
    if(lb < ub){
        int mid =(lb + ub)/2;
        mergesort(p,lb,mid,temp);
        mergesort(p,mid+1,ub,temp);
        merge(p,lb,mid,ub,temp);
    }
}
int main()
{
    int n;
    printf("Enter the product You want to Add:");
    scanf("%d",&n);
    
    struct product p[n],temp[n];
    
    printf("Enter product name and price : ");
    for(int i=0; i<n; i++){
        scanf("%s %f",p[i].name,&p[i].price);
    }
    mergesort(p,0,n-1,temp);
    for(int i=0; i<n; i++){
        printf("%s - %.2f\n",p[i].name,p[i].price);
    }
    return 0;
}
