#include <iostream>

using namespace std;

/*
Remove N-th node from the end of a Linked List
Problem Statement: Given a linked list, and a number N. Find the Nth node from the end of this linked list and delete it. Return the head of the new modified linked list.

Example 1 :

Input: head = [1,2,3,4,5], n = 2

Output: [1,2,3,5]

Explanation: Refer Below Image
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

    ~Node()
    {
        int val = this->data;

        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout << "the deleted value is: " << val << endl;
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

void deleteAtPos(Node *&head, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;

        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
    }
}

// to remove nth element from back naive approach

void removeElement(Node *head, int n)
{
    Node *temp = head;
    int cnt = 0;

    while (temp)
    {
        cnt++;
        temp = temp->next;
    }

    int pos = (cnt - n) + 1;
    cout << pos << endl;

    deleteAtPos(head, pos);
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

    int n;
    cout << "Enter nth pos to remove element from back: " << endl;
    cin >> n;

    removeElement(head, n);

    display(head);

    return 0;
}

/*

Time complexity: O(N)  as we have to traverse whole list .


space complexity: O(1) as no extra space utilized

*/