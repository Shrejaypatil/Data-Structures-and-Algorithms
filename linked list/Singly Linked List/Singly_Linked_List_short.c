#include <stdio.h>
#include <stdlib.h>

// implement linked list

struct Node
{
    int data;
    struct Node *next;
};

int main()
{

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = first;

    first->data = 231;
    first->next = second;

    second->data = 21;d:\svnit\coding\INTEL\singlyll.c
    second->next = NULL;

    struct Node *temp = head;

    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}