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
struct node *insert_begin(struct node *head);
struct node *insert_end(struct node *head);
struct node *insert_middle(struct node *head);
void display();

int main()
{
    int n;
    printf("Enter no of elements you wish to create: ");
    scanf("%d", &n);
    create(n);

    head = insert_begin(head);
    head = insert_end(head);
    head = insert_middle(head);

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

struct node *insert_begin(struct node *head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to insert at beginning: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;
    else
        tail = newnode; // if list was empty

    head = newnode;
    return head;
}

struct node *insert_end(struct node *head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to insert at end: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    newnode->prev = tail;

    if (tail != NULL)
        tail->next = newnode;
    else
        head = newnode; // if list was empty

    tail = newnode;
    return head;
}

struct node *insert_middle(struct node *head)
{
    int pos, i = 1;
    printf("Enter position to insert (1-based index): ");
    scanf("%d", &pos);

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to insert at position %d: ", pos);
    scanf("%d", &newnode->data);

    if (pos <= 1)
    {
        return insert_begin(head);
    }

    struct node *temp = head;
    while (i < pos - 1 && temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }

    // Insert in between
    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;
    else
        tail = newnode; // if inserted at end

    temp->next = newnode;

    return head;
}

void display()
{
    struct node *temp = head;
    printf("\nDoubly Linked List elements:\n");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
