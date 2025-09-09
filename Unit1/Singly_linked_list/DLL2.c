#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;
struct node *tail=NULL;
void create(int n);
int total();
int count();
int main()
{
	int n;
	printf("How many elements do you wish to enter?\n");
	scanf("%d",&n);
	create(n);
	int t=total();
	printf("Sum is %d\n",t);
	int c=count();
	printf("No of elements are %d",c);
	return 0;
}
void create(int n)
{
	struct node *newnode;
	for(int i=0;i<n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter data:\n");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		newnode->prev=NULL;
		if(head==NULL)
		{
			head=tail=newnode;
		}
		else
		{
			tail->next=newnode;
			newnode->prev=tail;
			tail=newnode;
		}
	}
}
int total()
{
	struct node *temp=head;
	int sum=0;
	while(temp!=NULL)
	{
		sum+=temp->data;
		temp=temp->next;
	}
	return sum;
}
int count()
{
	struct node *temp=head;
	int s=0;
	while(temp!=NULL)
	{
		s++;
		temp=temp->next;
	}
	return s;
}




	