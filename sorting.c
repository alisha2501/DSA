
/*wap to creatte 4 functions bubble sort, selection sort, insertion sort, merge sort
before calling the sort function intialize the array with random inputs. find out the execution time for each sorting function for the same input*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void input(int[],int);
void display(int[],int);
void bubble_asc(int[], int);
void selection_desc(int[], int);
void insertion_asc(int[], int);
void mergeSort(int[],int,int);
void merge(int[],int,int,int);
int main(){
        int i,a[100],n,ch;
        n=1000000000;
        /*for(i=0;i<100;i++){
                A[i]=rand()%(n+1);
        }
        printf("Entered array:\n");
        for(i=0;i<1000000;i++){
                printf("%d\n",A[i]);
        }*/
        clock_t start,end;
        double cpu_time;
        start = clock();
	 do
        {
                printf("\n 1. INPUT \n 2. INPUT NORM \n 3. DISPLAY \n 4. BUBBLE SORT \n 5. SELECTION SORT \n 6. INSERTION SORT \n 7. MERGE SORT \n 8. EXIT\n");
                printf("enter choice\n");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: printf("enter length\n");
                                scanf("%d",&n);
				for(i=0;i<n;i++){
			  	//a[i]=rand()%(n+1);
				srand(time(NULL));
				}
                                break;
			case 2:  printf("enter length\n");
                                scanf("%d",&n);
                                for(i=0;i<n;i++){
                                a[i]=rand()%(n+1);
                                //srand(time(NULL));
                                }
                                break;
                        case 3: printf(" the elements are:\n");
                                display(a,n);
                                break;
                        case 4: start= clock();
				bubble_asc(a,n);
				end= clock();
				cpu_time = (double)(end - start);
				printf("Time taken : %lf seconds\n",cpu_time/CLOCKS_PER_SEC);
                                break;
                        case 5: start= clock();
                                selection_desc(a,n);
				end= clock();
                                cpu_time = (double)(end - start);
                                printf("Time taken : %lf seconds\n",cpu_time/CLOCKS_PER_SEC);
                                break;
                        case 6:	start= clock();
                                insertion_asc(a,n);
                                end= clock();
                                cpu_time = (double)(end - start);
                                printf("Time taken : %lf seconds\n",cpu_time/CLOCKS_PER_SEC);
                                break;
			case 7: start= clock();
                                mergeSort(a,0,n-1);
                                end= clock();
                                cpu_time = (double)(end - start);
                                printf("Time taken : %lf seconds\n",cpu_time/CLOCKS_PER_SEC);
                                break;
                        case 8: exit(0);
                                break;
                        default: printf(" invalid input");
                                break;
                }
        }
        while(ch!=8);
        return 0;
        /*mergeSort(A,0,100-1);
        end = clock();
        cpu_time = (double)(end - start);
        printf("Sorted array:\n");
        for(i=0;i<100;i++){
                printf("%d\n",A[i]);
        }
        printf("Time taken : %lf seconds\n",cpu_time/CLOCKS_PER_SEC);*/
}
void display(int a[100],int n)
{
        int i;
        for(i=0;i<n;i++)
        {
                printf("%d \t",a[i]);
        }
}
void bubble_asc(int a[], int n)
{
        int i,j,c;
        for(i=0;i<n;i++)
        {
                for(j=0;j<n-1;j++)
                {
                        if (a[i]<a[j])
                        {
                                c=a[i];
                                a[i]=a[j];
                                a[j]=c;
                        }
                }
        }
}

void insertion_asc(int a[], int n)
{
        int i,j,c;
        for(i=1;i<n;i++)
        {
                for(j=0;j<i;j++)
                {
                        if (a[i]< a[j])
                        {
                                c=a[i];
                                a[i]= a[j];
                                a[j]=c;
                        }
                }
        }
}
void selection_desc(int a[], int n)
{
        int i,j,c;
        for(i=0;i<n;i++)
        {
                for(j=i+1;j<n;j++)
                {
                        if (a[i]< a[j])
                        {
                                c=a[i];
                                a[i]= a[j];
                                a[j]=c;
                        }
                }
        }
}
void merge(int a[10], int l, int m, int h)
{
	int i,j,k;
	int temp[20000];
	i=l;
	j=m+1;
	k=l;
	while(i<=m && j<=h)
	{
		if(a[i]< a[j])
		{
			temp[k]=a[i];
			k++;
			i++;
		}
		else
		{
			temp[k]=a[j];
			j++;
			k++;
		}
	}
	while(i<=m)
	{
		temp[k]=a[i];
		k++;
		i++;
	}
	while(j<=h)
	{
		temp[k]=a[j];
		k++;
		j++;
	}
	for(i=l;i<=h;i++)
	{
		a[i]=temp[i];
	}
}

void mergeSort(int a[], int l, int h)
{
	int m;
	if(l<h)
	{
		m=(l+h)/2;
		mergeSort(a, l, m);
		mergeSort(a, m+1, h);
		merge(a,l,m,h);
	}
}


