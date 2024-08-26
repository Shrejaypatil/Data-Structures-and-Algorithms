#include <iostream>
using namespace std;

class Doublyll
{
public:
    int data;
    Doublyll *next;
    Doublyll *prev;

    Doublyll(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Doublyll()
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

void insertAtHead(Doublyll *&head, int data)
{
    Doublyll *temp = new Doublyll(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Doublyll *&tail, int data)
{
    Doublyll *temp = new Doublyll(data);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}

void insertAtPos(Doublyll *&head, Doublyll *&tail, int pos, int data)
{
    if (pos == 1)
    {
        insertAtHead(head, data);
        return;
    }

    Doublyll *temp = head;

    int cnt = 1;

    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    Doublyll *nodeToInsert = new Doublyll(data);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void printL(Doublyll *head)
{
    if (head == NULL)
    {
        cout << "empty list" << endl;
    }

    Doublyll *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteAtPos(Doublyll *&head, int pos)
{
    if (pos == 1)
    {
        Doublyll *temp = head;
        temp->next->prev = temp->prev;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Doublyll *curr = head;
        Doublyll *prev = NULL;

        int cnt = 1;

        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Doublyll *node1 = new Doublyll(10);

    Doublyll *head = node1;
    Doublyll *tail = node1;

    printL(head);

    insertAtHead(head, 1);
    printL(head);

    insertAtTail(tail, 20);
    printL(head);

    insertAtPos(head, tail, 4, 200);
    printL(head);

    deleteAtPos(head, 1);
    printL(head);

    deleteAtPos(head, 3);
    printL(head);

    return 0;
}