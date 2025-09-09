#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

void create(int n);
void display();
void reverse();

int main()
{
    int n;
    printf("Enter no of nodes to create: ");
    scanf("%d", &n);
    create(n);

    printf("\nOriginal DLL:\n");
    display();

    reverse();
    printf("\nReversed DLL:\n");
    display();

    return 0;
}

void create(int n)
{
    struct node *newnode;
    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverse()
{
    struct node *curr = head, *temp = NULL;

    
    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    
    if (temp != NULL)
    {
        head = temp->prev;
    }

   
    struct node *t = head;
    while (t != NULL && t->next != NULL)
        t = t->next;
    tail = t;
}

