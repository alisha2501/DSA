/*wap to take input for some products each product is having information
1. product id
2. product name
3. profit
4. weight
Using greedy algo. find the solution to accommodate the objects in the knapsack of capacity w */

#include <stdio.h>
#include <string.h>

#define maxlen 100

#include<stdio.h>
float p[10],v[10],w[10],t,x[10];
int W,n;
char pr;
void sort()
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=i+1;j<n;j++)
 {
 if(p[i]<p[j])
 {
 t=p[j];
 p[j]=p[i];
 p[i]=t;
 t=w[j];
 w[j]=w[i];
 w[i]=t;
 t=v[j];
 v[j]=v[i];
 v[i]=t;
 }
 }
}
float knapsack()
{
 int i;
 float total=0;
 for(i=0;i<=n;i++)
 {
 if(w[i]>W)
 {
 x[i]=W/w[i];
 total=total+p[i]*W;
 break;
 }
 else
 {
 x[i]=1;
 total=total+v[i];
 W=W-w[i];
 }
 }
 return total;
}
int main()
{
 int i;
 float s;
 printf("Enter the number of items: ");
 scanf("%d",&n);
/* printf("\nEnter the product name ");
 for(i=1;i<=n;i++)
 {
 scanf("%s",&pr[i]);
 }*/
 printf("\nEnter the weights of corresponding items: ");
 for(i=1;i<=n;i++)
 {
 scanf("%f",&w[i]);
 }
 printf("\nEnter the corresponding profit: ");
 for(i=1;i<=n;i++)
 {
 scanf("%f",&v[i]);
 }
 printf("\nEnter the maximum weight: ");
 scanf("%d",&W);
 for(i=1;i<=n;i++)
 {
 x[i]=0;
 p[i]=v[i]/w[i];
 }
 sort();
 s=knapsack();
 printf("\nTotal cost = %f",s);
 for(i=1;i<=n;i++)
 printf("\n%f",x[i]);
}
