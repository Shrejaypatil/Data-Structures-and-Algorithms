#include <stdio.h>
#include <stdlib.h>

/*
Queue is a linear data structure which follows the FIFO/ LILO pattern.

ex: people standing in a line for ticket

primary operations:

1. enqueue
2. dequeue
3. isEmpty
4. isFull
5. frontal

secondary operation:

display Queue

*/

struct Queue
{
    int rear;
    int front;
    int *arr;
};

// constructor for Queue to initialize values

void init(struct Queue *q, int size)
{
    q->arr = (int *)malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Queue *q, int size)
{
    if (q->rear == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct Queue *q, int size, int data)
{
    if (isFull(q, size))
    {
        printf("Queue  is Full \n");
        return;
    }
    else if (q->front == -1)
    {
        q->front++;
        q->rear++;
        q->arr[q->rear] = data;
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = data;
    }
}

int dequeue(struct Queue *q, int size)
{

    int popVal;
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
    }
    else if (q->front == q->rear)
    {

        popVal = q->arr[q->front];
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        popVal = q->arr[q->front];
        q->front++;
    }
    return popVal;
}

void frontal(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty \n");
    }
    else
    {
        printf("Chance of ticket: %d", q->front);
    }
}

void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty \n");
    }
    else
    {
        printf("\n****************************\n");
        printf("[ window ]");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf(" %d", q->arr[i]);
        }
        printf("\n****************************\n");
    }
}

int main()
{
    struct Queue *q;
    int size;
    printf("Enter queue capacity: ");
    scanf("%d", &size);
    init(q, size);

    enqueue(q, size, 10);
    enqueue(q, size, 20);
    enqueue(q, size, 30);

    // display(q);

    // enqueue(q, size, 40);
    // enqueue(q, size, 50);

    // display(q);

    // dequeue(q, size);

    display(q);

    dequeue(q, size);
    display(q);

    dequeue(q, size);
    display(q);

    dequeue(q, size);
    display(q);

    enqueue(q, size, 30);
    display(q);
    // dequeue(q, size);
    // dequeue(q, size);

    // display(q);

    return 0;
}