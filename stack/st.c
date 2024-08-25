#include <stdio.h>

#define size 5

typedef struct
{
    int top;
    int arr[size];
} Stack;

void init(Stack *st)
{
    st->top = -1;
}

int isEmpty(Stack *st)
{
    if (st->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(Stack *st)
{
    if (st->top >= size - 1)
    {
        return 1;
    }
    return 0;
}

void push(Stack *st, int data)
{
    if (isFull(st))
    {
        printf("Stack Overflow \n");
        return;
    }
    else
    {
        st->top++;
        st->arr[st->top] = data;
    }
}

int pop(Stack *st)
{
    int popVal;
    if (isEmpty(st))
    {
        printf("Stack Underflow \n");
        return 0;
    }
    else
    {
        popVal = st->arr[st->top];
        st->top--;
    }
    return popVal;
}

void peek(Stack *st)
{
    if (isEmpty(st))
    {
        printf("Stack Underflow \n");
        return;
    }
    else
    {
        printf("Top element: %d \n", st->arr[st->top]);
        return;
    }
}

void display(Stack *st)
{
    if (isEmpty(st))
    {
        printf("Stack Underflow \n");
        return;
    }
    else
    {
        printf("--------\n");
        for (int i = st->top; i >= 0; i--)
        {
            printf("%d \n", st->arr[i]);
        }
        printf("--------\n");
    }
}

int main()
{
    Stack st;

    init(&st);

    display(&st);

    push(&st, 10);

    display(&st);

    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);

    display(&st);

    peek(&st);

    push(&st, 60);

    display(&st);

    printf("Deleted element : %d \n", pop(&st));

    peek(&st);

    printf("Deleted element : %d \n", pop(&st));

    peek(&st);

    printf("Deleted element : %d \n", pop(&st));

    peek(&st);

    printf("Deleted element : %d \n", pop(&st));

    peek(&st);

    printf("Deleted element : %d \n", pop(&st));

    peek(&st);

    printf("Deleted element : %d \n", pop(&st));

    peek(&st);

    return 0;
}