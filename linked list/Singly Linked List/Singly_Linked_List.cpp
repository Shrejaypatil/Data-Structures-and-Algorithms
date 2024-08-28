#include <iostream>
using namespace std;

// singly ll

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Node is deleted with data: " << value << endl;
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
    Node *temp = head;

    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }

    int cnt = 1;

    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // insert at last
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void printL(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteAtNode(Node *&head, int pos)
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

Node *reverseL(Node *head, Node *tail)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *curr = head;
    Node *prev = NULL;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

void detectCycle(Node *head)
{
    Node *p1 = head;
    Node *p2 = head;

    while (p2->next != NULL && p2->next->next != NULL)
    {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2)
        {
            cout << "Cycle detected " << endl;
            return;
        }
    }
    cout << "Cycle not detected" << endl;
}

void cycle(Node *&head, Node *&tail)
{
    tail->next = head->next->next;
}

int main()
{
    Node *node1 = new Node(5);

    Node *head = node1;
    Node *tail = node1;
    printL(head);

    insertAtHead(head, 20);
    printL(head);

    insertAtTail(tail, 40);
    printL(head);

    insertAtPos(head, tail, 4, 1);
    printL(head);

    insertAtPos(head, tail, 2, 1);
    printL(head);

    deleteAtNode(head, 5);

    printL(head);

    insertAtTail(tail, 50);
    printL(head);

    insertAtTail(tail, 100);
    printL(head);

    insertAtTail(tail, 84);
    printL(head);

    insertAtTail(tail, -23);
    printL(head);

    insertAtTail(tail, 123);
    printL(head);

    insertAtTail(tail, 1000);
    printL(head);

    cycle(head, tail);

    // mid(head);

    detectCycle(head);

    return 0;
}