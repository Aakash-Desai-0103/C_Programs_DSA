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
int main()
{
	int n;
	printf("Enter no of elements you wish to display:\n");
	scanf("%d",&n);
	create(n);
	display();
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

		
		
		
