 

//binary search
#include<stdio.h>
void create_Array(int a[],int n){
    int i;
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}
void display_Array(int a[],int n){
    int i;
    printf("The array:\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}
void binary_Search(int a[],int n){
    int i,k,flag=0;
    printf("Enter the value to be searched:");
    scanf("%d",&k);
    if(k==a[n/2]){
        printf("%d is found at %d position",k,(n+2)/2);
        flag = 1; 
    }
    else if(k>a[n/2]){
        for(i=(n+2)/2;i<n;i++){
            if(a[i]==k){
                printf("%d is found at %d position",k,i+1);{
                    flag = 2;
                    break;
                }
            }
        }
    }
    else if(k<a[n/2]){
        for(i=0;i<n/2;i++){
            if(a[i]==k){
                printf("%d is found at %d position",k,i+1);{
                    flag = 3;
                    break;
                }
            }
        }
    }
    if(flag==0){
        printf("Element not found");
    }
}
int main(){
    int a[100],n;
    printf("Enter the length of the array:");
    scanf("%d",&n);
    create_Array(a,n);
    // display_Array(a,n);
    binary_Search(a,n);
    return 0;
}
