#include <iostream>

using namespace std;

/*
Find middle element in a Linked List
Problem Statement: Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.

Examples:

Input Format:
( Pointer / Access to the head of a Linked list )
head = [1,2,3,4,5]

Result: [3,4,5]
( As we will return the middle of Linked list the further linked list will be still available )

Explanation: The middle node of the list is node 3 as in the below image.
*/

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

// Now to find Middle element using naive approach

int MidEle(Node *head)
{
    Node *temp = head;

    int cnt = 0;

    while (temp)
    {
        cnt++;
        temp = temp->next;
    }

    temp = head;

    for (int i = 0; i < cnt / 2; i++)
        temp = temp->next;

    return temp->data;
}

// Now using two pointer method

int Middle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
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

    Node *n1 = new Node(30);

    Node *head = n1;
    Node *tail = n1;

    display(head);

    insertAtHead(head, 33);

    display(head);

    insertAtTail(tail, 40);

    display(head);

    insertAtPos(head, tail, 3, 50);

    display(head);

    insertAtPos(head, tail, 4, 60);

    display(head);

    insertAtTail(tail, 88);

    display(head);

    int mid = MidEle(head);

    cout << "Middle element is: " << mid << endl;

    mid = Middle(head);

    cout << "Middle element is: " << mid << endl;

    return 0;
}

/*

Naive approach: 
Time complexity: O(N)  as we have to traverse whole list.
space complexity: O(1) as no extra space utilized. 


two pointer:
Time complexity: O(N/2)  as we have to traverse whole list.
space complexity: O(1) as no extra space utilized. 

*/