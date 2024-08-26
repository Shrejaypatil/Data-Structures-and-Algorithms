#include <iostream>

using namespace std;

/*
Find intersection of Two Linked Lists
Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

Examples:

Example 1:
Input:
List 1 = [1,3,1,2,4], List 2 = [3,2,4]
Output:
2
Explanation: Here, both lists intersecting nodes start from node 2.
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

// Code to find intersection

int intersecNode(Node *head, Node *head1)
{
    Node *d1 = head;
    Node *d2 = head1;

    int cnt1 = 0, cnt2 = 0;

    while (cnt1 < 2 || cnt2 < 2)
    {
        if (d1 == d2)
        {
            return d1->data;
        }

        if (!d1->next)
        {
            d1 = head1;
            cnt1++;
        }

        if (!d2->next)
        {
            d2 = head;
            cnt2++;
        }

        d1 = d1->next;
        d2 = d2->next;
    }
    return 0;
}

Node *intersectionPresent(Node *head1, Node *head2)
{
    Node *d1 = head1;
    Node *d2 = head2;

    while (d1 != d2)
    {
        d1 = d1 == NULL ? head2 : d1->next;
        d2 = d2 == NULL ? head1 : d2->next;
    }

    return d1;
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

    Node *n1 = new Node(2);

    // make head and tail
    Node *head = n1;
    Node *tail = n1;

    insertAtTail(tail, 4);

    insertAtTail(tail, 3);

    Node *n2 = new Node(5);

    Node *head1 = n2;
    Node *tail1 = n2;

    insertAtTail(tail1, 6);

    insertAtTail(tail1, 4);

    cout << "linked list 1: " << endl;
    display(head);

    cout << "linked list 2: " << endl;
    display(head1);

    head->next->next->next = head1->next;

    int IntersectingNode = intersecNode(head, head1);

    cout << "Intersecting Node is: " << IntersectingNode << endl;

    // Node* Inter=intersectionPresent(head,head1);

    // cout << "Intersecting Node is: " << Inter->data << endl;

    return 0;
}

/*

Time complexity: O(N)  as we have to traverse whole list .


space complexity: O(1) as no extra space utilized

*/