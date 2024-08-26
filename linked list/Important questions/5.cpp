#include <iostream>
#include <vector>

using namespace std;

/*
Add two numbers represented as Linked Lists
Problem Statement: Given the heads of two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

Examples:

Input Format:
(Pointer/Access to the head of the two linked lists)

num1  = 243, num2 = 564

l1 = [2,4,3]
l2 = [5,6,4]

Result: sum = 807; L = [7,0,8]

Explanation: Since the digits are stored in reverse order, reverse the numbers first to get the or original number and then add them as → 342 + 465 = 807. Refer to the image below.
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

// to find their sum and append to new list

void sumOfLinkedList(Node *head, Node *head1)
{
    int carry = 0;

    Node *n3 = new Node(0);

    Node *head2 = n3;
    Node *tail2 = n3;

    while (head)
    {
        int sum = head->data + head1->data + carry;
        if (sum > 9)
        {
            int digit = sum % 10;
            carry = sum / 10;
            insertAtTail(tail2, digit);
        }
        else
        {
            insertAtTail(tail2, sum);
            carry = 0;
        }
        head = head->next;
        head1 = head1->next;
    }

    cout << "thes sum is in linked list 3: " << endl;
    display(head2->next);
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

    // new linked list for sum

    sumOfLinkedList(head, head1);

    return 0;
}

/*

Time complexity: O(N+M)
space complexity: O(N+m)

*/