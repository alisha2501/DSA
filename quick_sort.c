#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void input(int[],int);
void display(int[],int);
int partition(int[], int, int);
void quick_Sort(int[],int, int);
//void swap(int a , int b);

int main()
{
        int i,n,a[1000];
	clock_t start,end;
        double cpu_time;
        start = clock();
        printf("enter length of the array:\n");
        scanf("%d",&n);
        //printf("enter the elemnts of the array:\n");
        input(a,n);
        printf("\nthe array before sorting:\n");
        display(a,n);
	start= clock();
        quick_Sort(a,0 , n - 1);
	end= clock();
	cpu_time = (double)(end - start);
	//printf("Time taken : %lf seconds\n",cpu_time/CLOCKS_PER_SEC);
        printf("\nthe array after sorting:\n");
        display(a,n);
	printf("\nTime taken : %lf seconds\n",cpu_time/CLOCKS_PER_SEC);
}
void input(int a[], int n)
{
	  int i;
          //printf("enter length\n");
	  //scanf("%d",&n);
	  for(i=0;i<n;i++){
		  a[i]=rand()%(n+1);
		  //srand(time(NULL));
	  }
}

void display(int a[10],int n)
{
        int i;
        for(i=0;i<n;i++)
        {
                printf("%d \t",a[i]);
        }
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


void quick_Sort(int a[],int start , int end){

    if (start < end){
        int pivot = partition(a, start , end);
        quick_Sort(a,start , pivot - 1);
        quick_Sort(a,pivot + 1 , end);
    }
}

