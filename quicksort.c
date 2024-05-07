#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int[],int,int);
int RandRange(int, int);
int randpartition(int[],int,int);
void randquicksort(int[],int,int);


int main(){
    int n;
    printf("Enter the number of inputs: ");
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++) {  
        a[i]=rand()%(10000 + 1);  
    } 
    /*printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }*/
    printf("The list is: \n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    randquicksort(a,0,n-1);
    printf("The sorted list is: \n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}


int partition(int a[],int l,int h){
    int i,j,pivot,temp;
    pivot=a[h];
    j=l-1;
    for(i=l;i<h;i++){
        if(a[i]<pivot){
            j=j+1;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[j+1];
    a[j+1]=a[h];
    a[h]=temp;
    return j+1;
}
int RandRange(int Min, int Max)
{
    int diff = Max-Min;
    return (int) (((double)(diff+1)/RAND_MAX) * rand() + Min);
}
int randpartition(int a[],int l,int h){
    int i=RandRange(l,h);
    int temp=a[i];
    a[i]=a[h];
    a[h]=temp;
    return partition(a,l,h);
}
void randquicksort(int a[],int l,int h){
    if(l<h){
        int p=randpartition(a,l,h);
        randquicksort(a,l,p-1);
        randquicksort(a,p+1,h);
    }
}

