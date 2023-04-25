#include<stdio.h>
#include<stdlib.h>
#include<time.h>
double h;
struct node
{
	int data;
	struct node* next;
}*list=NULL,*temp,*p,*back;

typedef struct node NODE;

void insert(int item)
{
temp=(NODE*)malloc(sizeof(NODE));
temp->data=item;
if(list==NULL)
{
temp->next=NULL;
list=temp;
}
else
{
p=list;
while(p->next!=NULL)
{
p=p->next;
}
p->next=temp;
temp->next=NULL;
}
}

void remov()
{
int item,search;
printf("ENTER THE ELEMENT:\n");
scanf("%d",&search);
back=list;
p=list->next;
if(list->data==search)
{
   temp=list;
   list=list->next;
   free(temp);
}
else
{
   while(p->next!=NULL&&p->data!=search)
     {
       back=back->next;
       p=p->next;
     }
       back->next=p->next;
       free(p);
}
}


void display()
{
if(list==NULL)
	printf("List is empty");
else
{
for(p=list;p!=NULL;p=p->next)
	printf("%d\t",p->data);
}
}


int main()
{
int i,c,n,k,item,m;
clock_t t1,t2;
printf("Enter the no.of elements\n");
scanf("%d",&n);
printf("Enter the elements\n");
for(i=0;i<n;i++)	
{
scanf("%d",&item);
insert(item);
}
printf(" Elements you entered are:\n");
display();
do
{
t1=clock();
printf("\n1.Remove\n2.Next largest\n");
scanf("%d",&c);
	
if(c==1)
{		
remov();
printf("AFTER REMOVING:\n");
display();
}
if(c==2)
{
  p=list;
  printf("Enter the element\n");
  scanf("%d",&item);
  while(p->next!=NULL&&p->data!=item)
	p=p->next;
	    if(p->next!=NULL)
		{
		while(p->data<=item)
			p=p->next;
		printf("%d is largest element",p->data);
		}
		else
			printf("No larger element");
	}
t2=clock();
h=(t2-t1)/(double)CLOCKS_PER_SEC;
printf("\nTime:%f\n",h);
printf("\nDo you want to continue??:press 1 or 0\n");
scanf("%d",&k);
}
while(k==1);
}

