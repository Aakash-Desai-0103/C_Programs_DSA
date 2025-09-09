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
void display();
void reverse_display();
int main()
{
	int n;
	printf("Enter no of nodes:\n");
	scanf("%d",&n);
	create(n);
	printf("Displayed in forward order:\n");
	display();
	printf("Displayed in reverse order:\n");
	reverse_display();
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
void display()
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void reverse_display()
{
	struct node *temp=tail;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->prev;
	}
	printf("\n");
}

			
		
