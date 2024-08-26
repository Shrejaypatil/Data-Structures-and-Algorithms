#include <iostream>

using namespace std;

/*
Detect a Cycle in a Linked List
In this article, we will solve the most asked interview question: Detect a Cycle in a Linked List

Problem Statement: Given head, the head of a linked list, determine if the linked list has a cycle in it. There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.

Return true if there is a cycle in the linked list. Otherwise, return false.

Examples:

Example 1:
Input:
 Head = [1,2,3,4]
Output:
 true
Explanation: Here, we can see that we can reach node at position 1 again by following the next pointer. Thus, we return true for this case.
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

// Code to find loop in linked list

bool detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast->next && fast)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

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

    head->next->next = head->next;

    if (detectCycle(head))
    {
        cout << "Cycle detected" << endl;
    }
    else
    {
        cout << "Cycle Not Deteted" << endl;
    }

    return 0;
}

/*

Time complexity: O(2N)  as we have to traverse whole list .


space complexity: O(1) as no extra space utilized.

*/