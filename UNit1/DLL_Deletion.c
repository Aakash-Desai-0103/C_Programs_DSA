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
struct node *del_begin(struct node *head);
struct node *del_end(struct node *head);
struct node *del_middle(struct node *head);

int main()
{
    int n;
    printf("Enter no of nodes to create: ");
    scanf("%d", &n);
    create(n);

    printf("\nOriginal DLL:\n");
    display();

    head = del_begin(head);
    printf("\nAfter deleting from beginning:\n");
    display();

    head = del_end(head);
    printf("\nAfter deleting from end:\n");
    display();

    head = del_middle(head);
    printf("\nAfter deleting from middle:\n");
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

struct node *del_begin(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }

    struct node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL; 

    free(temp);
    return head;
}

struct node *del_end(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    struct node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;

    free(temp);
    return head;
}

struct node *del_middle(struct node *head)
{
    int pos, i = 1;
    printf("Enter position to delete (1-based index): ");
    scanf("%d", &pos);

    if (head == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }

    if (pos == 1)
    {
        return del_begin(head);
    }

    struct node *temp = head;
    while (i < pos && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Invalid position!\n");
        return head;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev; 

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
    return head;
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

