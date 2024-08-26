#include <iostream>

using namespace std;

/*
Delete given node in a Linked List : O(1) approach
Problem Statement: Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list instead, you will be given access to the node to be deleted directly. It is guaranteed that the node to be deleted is not a tail node in the list.

Examples:

Example 1:
Input:
 Linked list: [1,4,2,3]
       Node = 2
Output:
Linked list: [1,4,3]
Explanation: Access is given to node 2. After deleting nodes, the linked list will be modified to [1,4,3].

Example 2:
Input:
 Linked list: [1,2,3,4]
       Node = 1
Output: Linked list: [2,3,4]
Explanation:
 Access is given to node 1. After deleting nodes, the linked list will be modified to [2,3,4].
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

// delete a node in O(1)

void deleteInOne(Node *&n1)
{
    n1 = n1->next;
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

    // display(head);

    insertAtHead(head, 30);

    // display(head);

    insertAtTail(tail, 40);

    // display(head);

    insertAtPos(head, tail, 3, 50);

    // display(head);

    insertAtPos(head, tail, 4, 60);

    display(head);

    deleteInOne(head->next->next->next);

    display(head);

    return 0;
}

/*

Time complexity: O(1) 

space complexity: O(1) as no extra space utilized.

*/