#include <iostream>
using namespace std;

class Queue
{
public:
    int front;
    int rear;
    int *arr;
    int size;

    Queue(int s)
    {
        this->front = -1;
        this->rear = -1;
        this->size = s;

        this->arr = new int[size];

        for (int i = 0; i < size; i++)
        {
            arr[i] = -1;
        }
    }

    /*
    1. push
    2. pop
    3. top
    4. isempty
    5. isfull
    6. display
    */

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (front == 0 && rear == size - 1)
        {
            return true;
        }
        else if (rear == front - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Circular Queue is Full \n";
        }
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = data;
        }
    }

    int dequeue()
    {
        int popVal;
        if (isEmpty())
        {
            cout << "Circular Queue is Empty \n";
        }
        else if (front == rear)
        {
            popVal = arr[front];
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else
        {
            popVal = arr[front];
            arr[front] = -1;
            front = (front + 1) % size;
        }
        return popVal;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Circular Queue is Empty \n";
        }
        else
        {
            cout << "Data item at front: " << arr[front] << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Circular Queue is Empty \n";
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter size of Circular Queue: ";
    cin >> n;

    Queue q(n);

    int choice;

    do
    {
        cout << "Below are the choices" << endl;
        cout << "1.Insert \n";
        cout << "2.Delete \n";
        cout << "3.Frontmost \n";
        cout << "4.Display \n";
        cout << "5.Exit \n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int d;
            cout << "Enter data: ";
            cin >> d;
            q.enqueue(d);

            break;

        case 2:
            cout << "The data item deleted is: " << q.dequeue() << endl;

            break;

        case 3:

            q.peek();

            break;

        case 4:

            q.display();

            break;

        default:

            cout << "Enter Correct Choice \n";
        }

    } while (choice != 5);

    return 0;
}