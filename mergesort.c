//WAP to sort elements of a givenn array using merge sort in ascending order. 
//Derive the recurrence relationship for the recurrence func performing merge sort and solve the recurrence using recurrence tree method.

#include<stdio.h>
#include<stdlib.h>
void input(int[],int);
void display(int[],int);
void mergeSort(int[],int,int); 
void merge(int[],int,int,int);
int main()
{
	int i,n,a[10];
	printf("enter length of the array:\n");
	scanf("%d",&n);
	printf("enter the elemnts of the array:\n");
	input(a,n);
	printf("the array before sorting:\n");
        display(a,n);
	mergeSort(a,0,n-1);
	printf("\nthe array after sorting:\n");
        display(a,n);
}
void input(int a[10], int n)
{
        int i;
        for (i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
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
void merge(int a[10], int l, int m, int h)
{
	int i,j,k;
	int temp[20];
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
