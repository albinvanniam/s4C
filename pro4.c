#include <stdio.h>
#include<stdlib.h>
#include<time.h>
void binary_search(int a[],int n)
{
int i,l,u,mid,k;
printf("\nEnter element to be searched");
scanf("%d",&k);
l=0;
u=n-1;
mid=(l+u)/2;
while(l<=u)
	{
		if(a[mid]<k)
		l=mid+1;  
		else if(a[mid]==k)
		{
		printf("Element found");
		break;
		}
		else
		u=mid-1;
		mid=(l+u)/2;
	}
if(l>u)
	printf("Not found\n");
}

void main()
{
	double m;
	clock_t t1,t2;
	int a[5000],i,n,c,ch;
	printf("\nEnter no of elements");
	scanf("%d",&n);
	FILE *fp;
	fp=fopen("binary.dat","a");
	for (i=0;i<n;i++)
		{
		scanf("%d",&a[i]);
		}
	t1=clock();
	for (i=0;i<n;i++)
		{
		printf("%d\t",a[i]);
		}
	binary_search(a,n);
	t2=clock();
	m=(t2-t1)/(double)CLOCKS_PER_SEC;
	printf("%f",m);
	fprintf(fp,"\n-%d\t %f",n,m);
	fclose(fp);
}
