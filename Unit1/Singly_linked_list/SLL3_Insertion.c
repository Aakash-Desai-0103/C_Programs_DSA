#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node *head=NULL;
void create(int n);
struct node * insert_begin(struct node *head);
struct node * insert_middle(struct node *head);
struct node * insert_end(struct node *head);
int count();
void display();
int main()
{
	int n;
	printf("Enter no of elements you wish to enter:\n");
	scanf("%d",&n);
	create(n);
	head=insert_begin(head);
	head=insert_end(head);
	head=insert_middle(head);
	
	display();
	return 0;
}
void create(int n)
{
	struct node *temp,*newnode;
	for(int i=0;i<n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter data:\n");
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
struct node * insert_begin(struct node *head)
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	printf("Enter data you wish to add at beginning\n");
	scanf("%d",&new->data);
	if(head==NULL)
	{
		return new;
	}
	else
	{
		new->next=head;
		head=new;
	}
	return head;
}
struct node * insert_end(struct node *head)
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	printf("Enter the data you wish to enter:\n");
	scanf("%d",&new->data);
	if(head==NULL)
	{
		return new;
	}
	struct node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=new;
	new->next=NULL;
	return head;
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
struct node * insert_middle(struct node *head)
{
	int pos;
	printf("Insert position where you want to enter:\n");
	scanf("%d",&pos);
	if(pos<0)
	{
		printf("Not a valid position");
		return head;
	}
	else if(pos==0)
	{
		return insert_begin(head);
	}
	int c=count();
	if(pos==c)
	{
		return insert_end(head);
	}
	struct node *temp=head;
	for(int i=0;i<pos-1;i++)
	{
		temp=temp->next;
	}
	struct node *new=(struct node *)malloc(sizeof(struct node));
	printf("Enter data:\n");
	scanf("%d",&new->data);
	new->next=temp->next;
	temp->next=new;
	return head;
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

	
	

	
