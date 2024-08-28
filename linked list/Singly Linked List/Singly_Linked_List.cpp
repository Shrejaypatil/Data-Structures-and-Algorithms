#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->next = NULL;
        this->data = d;
    }

    // destructor

    ~Node()
    {
        int popVal = this->data;

        if (this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }

        cout << "The deleted data is: " << popVal << endl;
    }
};

/*
Operations:

1. insertAtHead
2. insertAtTail
3. insertAtPos
4. deleteAtHead
5. deleteAtTail // cant delete at tail as we may loose tail link
6. deleteAtPos

*/

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
    }
    else
    {
        Node *curr = head;
        Node *prev = head;

        int cnt = 0;

        while (cnt < pos - 1)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr->next == NULL)
        {
            insertAtTail(tail, d);
        }

        Node *nodeToInsert = new Node(d);

        prev->next = nodeToInsert;
        nodeToInsert->next = curr;
    }
}

void deleteAtHead(Node *&head)
{

    // first check if single element in list
    if (head->next == NULL)
    {
        delete head;
    }
    else
    {
        Node *temp = head;

        head = head->next;

        temp->next = NULL;

        delete temp;
    }
}

void deleteAtPos(Node *&head, Node *&tail, int pos)
{
    if (pos == 1)
    {
        deleteAtHead(head);
    }
    else
    {
        Node *curr = head;
        Node *prev = head;

        int cnt = 0;

        while (cnt < pos - 1)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr->next == NULL)
        {
            tail = prev;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void display(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
}

int main()
{
    Node *root = new Node(10);

    Node *head = root;

    Node *tail = root;

    insertAtHead(head, 20);

    display(head);

    insertAtTail(tail, 30);

    display(head);

    insertAtPos(head, tail, 2, 100);

    display(head);

    insertAtTail(tail, 60);

    display(head);

    insertAtPos(head, tail, 3, 1101);

    display(head);

    insertAtPos(head, tail, 5, 5001);

    display(head);

    insertAtHead(head, 70);

    display(head);

    deleteAtHead(head);

    display(head);

    deleteAtPos(head, tail, 3);

    display(head);

    deleteAtPos(head, tail, 6);

    display(head);

    insertAtTail(tail, 450);

    display(head);

    insertAtTail(tail, 80);

    display(head);

    deleteAtPos(head, tail, 7);

    display(head);

    insertAtTail(tail, 80);

    display(head);

    deleteAtPos(head, tail, 4);

    display(head);

    return 0;
}