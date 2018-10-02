#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void heapify(int a[],int n,int i)
{
	int lar=i;
	int l=2*i+1,r=2*i+2;
	if(l<n&&a[l]>a[lar])
		lar=l;
	
	if(r<n&&a[r]>a[lar])
		lar=r;
	if(lar!=i)
	{
		int t=a[i];
		a[i]=a[lar];
		a[lar]=t;
		heapify(a,n,lar);
	}
}
void heapsort(int a[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
		heapify(a,n,i);
	for(i=n-1;i>=0;i--)
	{
		int t=a[0];
		a[0]=a[i];
		a[i]=t;
		heapify(a,i,0);
	}
}
void main()
{
	int i,n;
	printf("Enter the Size");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	heapsort(a,n);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
