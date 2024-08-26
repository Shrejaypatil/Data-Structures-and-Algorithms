#include <iostream>

using namespace std;

/*
Reverse a Linked List
Problem Statement: Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.

Examples:

Input Format:
head = [3,6,8,10]
This means the given linked list is 3->6->8->10 with head pointer at node 3.

Result:
Output = [10,6,8,3]
This means, after reversal, the list should be 10->6->8->3 with the head pointer at node 10.

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

// Now code for reversing singly LL

Node *reverseL(Node *&head, Node *&tail)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    else
    {
        Node *forward = NULL;
        Node *prev = NULL;
        Node *curr = head;

        // to handle tail here

        tail = head;

        while (curr)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
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

int main()
{

    Node *n1 = new Node(20);

    // make head and tail
    Node *head = n1;
    Node *tail = n1;

    display(head);

    insertAtHead(head, 30);

    display(head);

    insertAtTail(tail, 40);

    display(head);

    insertAtPos(head, tail, 3, 50);

    display(head);

    insertAtPos(head, tail, 4, 60);

    display(head);

    head = reverseL(head, tail);

    display(head);

    insertAtTail(tail, 55);

    display(head);

    insertAtHead(head, 36);

    display(head);

    return 0;
}

/*

Time complexity: O(N)  as we have to traverse whole list .


space complexity: O(1) as no extra space utilized

*/