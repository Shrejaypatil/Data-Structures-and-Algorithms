#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

void insertAtHead(node **head, int d)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = d;
    temp->next = NULL;
    temp->next = *head;
    *head = temp;
}

void insertAttail(node **tail, int d)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = d;
    temp->next = NULL;
    (*tail)->next = temp;
    (*tail) = temp;
}

void insertAtPos(node **head, node **tail, int d, int pos)
{
    if (pos == 1)
    {
        insertAtHead(head, d);
    }
    else
    {
        int cnt = 0;
        node *temp = (node *)malloc(sizeof(node));
        temp = *head;

        while (cnt < pos)
        {
            temp = temp->next;
            cnt++;
        }

        if (temp->next == NULL)
        {
            insertAttail(tail, d);
        }

        node *nodetoinsert = (node *)malloc(sizeof(node));
        nodetoinsert->data = d;
        nodetoinsert->next = temp->next;
        temp->next = nodetoinsert;
    }
}

void display(node *head)
{
    node *temp = (node *)malloc(sizeof(node));
    temp = head;

    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    node *n1 = (node *)malloc(sizeof(node));
    n1->data = 10;
    n1->next = NULL;
    node *head = (node *)malloc(sizeof(node));
    node *tail = (node *)malloc(sizeof(node));

    head = n1;
    tail = n1;

    display(head);

    insertAtHead(&head, 30);

    display(head);

    insertAtHead(&head, 50);

    display(head);

    insertAttail(&tail, 20);

    display(head);

    insertAtPos(&head, &tail, 40, 2);

    display(head);

    return 0;
}