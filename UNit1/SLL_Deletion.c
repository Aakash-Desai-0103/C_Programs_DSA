#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node *head=NULL;
void create(int n);
int count();
struct node * del_begin(struct node *head);
struct node * del_middle(struct node *head);
struct node * del_end(struct node *head);
int count();
void display();
int main()
{
	int n;
	printf("Enter no of elements you wish to enter:\n");
	scanf("%d",&n);
	create(n);
	head=del_begin(head);
	head=del_end(head);
	head=del_middle(head);
	
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
struct node * del_begin(struct node *head)
{
	if(head==NULL)
	{
		printf("Empty List");
		return head;
	}
	else
	{
		struct node *temp=head;
		head=head->next;
		free(temp);
		return head;
	}
}

struct node * del_end(struct node *head)
{
	if(head==NULL)
	{
		printf("Empty List");
		return head;
	}
	else if(head->next==NULL)
	{
		free(head);
		return NULL;
	}
	else
	{
		struct node *temp=head;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
		return head;
	}
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

struct node * del_middle(struct node *head)
{
	int pos;
	printf("Enter position you wish to delete:\n");
	scanf("%d",&pos);
	int c=count();
	if(pos<0||pos>c)
	{
		printf("Invalid position");
		return head;
	}
	if(pos==1)
	{
		return del_begin(head);
	}
	if(pos==c)
	{
		return del_end(head);
	}
	struct node *temp=head;
	for(int i=1;i<pos-1;i++)
	{
		temp=temp->next;
	}
	struct node *del=temp->next;
	temp->next=del->next;
	free(del);
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

	


					
