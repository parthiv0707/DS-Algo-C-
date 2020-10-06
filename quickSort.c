#include <stdio.h>
#include <stdlib.h>
void printarray(int arr[],int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("%d ",arr[i] );
	}
	printf("\n");
}
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int arr[],int l,int h)
{
	int a,b,c;
	c=arr[h];
	b=l-1;
	for(a=l;a<=h-1;a++)
	{
		if(arr[a]<=c)			
		{
			b+=1;
			swap(&arr[a],&arr[b]);
		}			
	}
	swap(&arr[b+1],&arr[h]);
	return b+1;
}
int quicksort(int arr[],int l,int h)
{
	int q;
	if(l<h)
	{
		q=partition(arr,l,h);
		quicksort(arr,l,q-1);
		quicksort(arr,q+1,h);
	}
}
int main()
{
	int i,j,n;
	scanf("%d",&n);
	int arr[n];
	for (j = 0; j < n; ++j)
	{
		scanf("%d",&arr[j]);
	}
	quicksort(arr,0,n-1);
	printarray(arr,n);
	return 0;
}
