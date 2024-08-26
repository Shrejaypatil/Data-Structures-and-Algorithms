#include <iostream>

using namespace std;

/*
Merge two sorted Linked Lists
In this article, we will solve the most asked coding interview question: ” Merge two sorted Linked Lists “

Problem Statement: Given two singly linked lists that are sorted in increasing order of node values, merge two sorted linked lists and return them as a sorted list. The list should be made by splicing together the nodes of the first two lists.

Example 1:

Input Format :
l1 = {3,7,10}, l2 = {1,2,5,8,10}

Output :
{1,2,3,5,7,8,10,10}

*/

// first we will create a singly linked list

class Node
{

public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPos(Node *&head, Node *&tail, int pos, int d)
{
    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }
    else
    {

        Node *temp = head;
        int cnt = 1;

        while (cnt < pos - 1)
        {
            temp = temp->next;
            cnt++;
        }

        if (temp->next == NULL)
        {
            insertAtTail(tail, d);
            return;
        }

        Node *NodeToInsert = new Node(d);
        NodeToInsert->next = temp->next;
        temp->next = NodeToInsert;
    }
}

void display(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// merging two linked list recursion
void merger(Node *head, Node *head1)
{
    // if (head == NULL)
    //     return head1;

    // if (head1 == NULL)
    //     return head;

    Node *temp = head;
    Node *temp1 = head1;

    Node *n3;

    if (temp->data <= temp1->data)
    {
        n3 = new Node(temp->data);
        temp = temp->next;
    }
    else
    {
        n3 = new Node(temp1->data);
        temp1 = temp1->next;
    }

    Node *head2 = n3;
    Node *tail2 = n3;

    while (temp->next != NULL && temp1->next != NULL)
    {
        if (temp->data <= temp1->data)
        {
            insertAtTail(tail2, temp->data);
            temp = temp->next;
        }
        else
        {
            insertAtTail(tail2, temp1->data);
            temp1 = temp1->next;
        }
    }

    while (temp)
    {
        insertAtTail(tail2, temp->data);
        temp = temp->next;
    }

    while (temp1)
    {
        insertAtTail(tail2, temp1->data);
        temp1 = temp1->next;
    }

    display(head2);
}

int main()
{

    Node *n1 = new Node(20);

    // make head and tail
    Node *head = n1;
    Node *tail = n1;

    display(head);

    insertAtHead(head, 10);

    display(head);

    insertAtTail(tail, 80);

    display(head);

    insertAtPos(head, tail, 3, 50);

    display(head);

    insertAtPos(head, tail, 4, 60);

    cout << "Linked list 1:" << endl;
    display(head);

    Node *n2 = new Node(70);

    // make head and tail
    Node *head1 = n2;
    Node *tail1 = n2;

    display(head1);

    insertAtHead(head1, 40);

    display(head1);

    insertAtTail(tail1, 180);

    display(head1);

    insertAtPos(head1, tail1, 3, 120);

    display(head1);

    insertAtPos(head1, tail1, 4, 160);

    cout << "Linked list 2: " << endl;
    display(head1);

    merger(head, head1);

    return 0;
}


/*

// here we have used naive approach

time complexity: 0(N+M)
space complecity:O(N+M)


*/