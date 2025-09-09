#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void create(int n);
void display();
int total();
int count();
int main()
{
	int n;
	printf("Enter no of elements you wish to display:\n");
	scanf("%d",&n);
	create(n);
	display();
	int sum=total();
	printf("The sum of all nodal elements are\t %d",sum);
	int count1=count();
	printf("No of nodes in the SLL are\t%d",count1);
	return 0;
}
void create(int n)
{
	struct node *temp,*newnode;
	for(int i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data:\n");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
	
	if(head==NULL)
	{
		head=temp=newnode;
	}
	else
	{
		temp->next=newnode;
		temp=newnode;
	}
}
}
int total()
{
	struct node *temp=head;
	int t=0;
	while(temp!=NULL)
	{
		t+=temp->data;
		temp=temp->next;
	}
	return t;
}
int count()
{
	struct node *temp=head;
	int c=0;
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	return c;
}

void display()
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

