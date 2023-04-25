#include<stdio.h>
#include<time.h>
double m;
void main()
{clock_t t1,t2;
FILE *fp;
fp=fopen("linear.dat","a");
int a[50];
int n,srkey,i;
int flag=0;
printf("Enter total no. of element's:");
scanf("%d",&n);
printf("\nEnter the elements:");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
t1=clock();
printf("\nEnter the search key:");
scanf("%d",&srkey);
for(i=0;i<n;i++)
{ 
     if(a[i]==srkey)
	{ flag=1;
	}
}    
  
if(flag==0)
 { printf("Element not found");
 }

else if(flag==1)
 {
   printf("Element  found");
 }
t2=clock();
m=(t2-t1)/(double)CLOCKS_PER_SEC;
printf("\nTime:%f",m);
fprintf(fp,"%d %f\n",n,m);
fclose(fp);
}

 

