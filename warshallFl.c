#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int n,i,j,**a,**p,k;
	double **w,**d,k1;
	printf("Enter the order of the weighted matrix:\t");
	scanf("%d",&n);

	a=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		a[i]=(int *)malloc(n*sizeof(int));

	p=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		p[i]=(int *)malloc(n*sizeof(int));

	w=(double **)malloc(n*sizeof(double *));
	for(i=0;i<n;i++)
		w[i]=(double *)malloc(n*sizeof(double));

	d=(double **)malloc(n*sizeof(double *));
	for(i=0;i<n;i++)
		d[i]=(double *)malloc(n*sizeof(double));

	printf("Enter the adjacency matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(a[i][j] == 1)
			{
				printf("Enter the weight of the vertices %d and %d\t",i,j);
				scanf("%lf",&k1);
				w[i][j]=k1;
			}
			else
			{
				if(i == j)
					w[i][j] = 0;
				else
					w[i][j]=INFINITY;
			}
		}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			d[i][j]=w[i][j];
			if(d[i][j]== INFINITY)
				p[i][j]=-1;
			else
				p[i][j]=i+1;
		}
	

	for(k=0; k<n;k++)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(d[i][j]>d[i][k]+d[k][j])
				{
					d[i][j]=d[i][k]+d[k][j];
					p[i][j]=p[k][j];
				}
	}
	
	printf("The final D matrix is given by :\n");
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%lf\t",d[i][j]);
		printf("\n");}
	printf("\n");
	printf("The final P matrix is given by :\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d\t",p[i][j]);
		printf("\n");}
	printf("\n");
}
}
